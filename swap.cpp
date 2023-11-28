#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

class ExtremelyLargeObject {
public:
    ExtremelyLargeObject() {
        cout << "Default constructor called." << endl;
    }

    // Constructor that creates a large array
    ExtremelyLargeObject(long long size) : largeArray(size) {
        // Use random_device to obtain a seed for the random number engine
        random_device rd;

        // Use mt19937 as the random number engine
        mt19937 gen(rd());

        // Generate a random integer between 1 and 100 (inclusive)
        uniform_int_distribution<int> distribution(1, 100);

        // Generate a random name for this object
        name = to_string(distribution(gen));

        // Initialize the array with random integers
        for (long long i = 0; i < size; ++i) {
            largeArray[i] = distribution(gen);
        }

        cout << "Constructor called for " << name << endl;
    }

    // Copy constructor
    ExtremelyLargeObject(const ExtremelyLargeObject& other) {
        largeArray = other.largeArray;
        name = other.name;
        cout << "Copy constructor called." << endl;
    }

    // Move constructor
    ExtremelyLargeObject(ExtremelyLargeObject&& other) {
        largeArray = std::move(other.largeArray);
        name = std::move(other.name);
        cout << "Move constructor called." << endl;
    }

    // Destructor
    ~ExtremelyLargeObject() {
        cout << "Destroying an extremely large object." << endl;
    }

    // Copy assignment operator
    ExtremelyLargeObject& operator=(const ExtremelyLargeObject& other) {
        if (this != &other) {
            largeArray = other.largeArray;
            name = other.name;
        }
        cout << "Copy assignment operator called." << endl;
        return *this;
    }

    // Move assignment operator
    ExtremelyLargeObject& operator=(ExtremelyLargeObject&& other) noexcept {
        if (this != &other) {
            largeArray = std::move(other.largeArray);
            name = std::move(other.name);
        }
        cout << "Move assignment operator called." << endl;
        return *this;
    }

    int gerValue(long long index) {
        return largeArray[index];
    }

    string getName() {
        return name;
    }

private:
    vector<int> largeArray; // A large array fill with random integers
    string name;            // A random id for this object
};

int main() {
    // Measure the time to create E1
    auto startE1 = chrono::high_resolution_clock::now();
    cout << "Start creating E1 with a size of 400MB." << endl;
    ExtremelyLargeObject E1(100000000);
    auto stopE1 = chrono::high_resolution_clock::now();
    auto durationE1 = chrono::duration_cast<chrono::microseconds>(stopE1 - startE1);
    cout << "Time taken to create E1: " << durationE1.count() << " microseconds." << endl;

    // Measure the time to create E2
    auto startE2 = chrono::high_resolution_clock::now();
    cout << "Start creating E2 with a size of 400MB." << endl;
    ExtremelyLargeObject E2(100000000);
    auto stopE2 = chrono::high_resolution_clock::now();
    auto durationE2 = chrono::duration_cast<chrono::microseconds>(stopE2 - startE2);
    cout << "Time taken to create E2: " << durationE2.count() << " microseconds." << endl;

    // Perform a std::swap
    cout << "Performing a std::swap." << endl;
    auto startStdSwap = chrono::high_resolution_clock::now();
    std::swap(E1, E2);
    auto stopStdSwap = chrono::high_resolution_clock::now();
    auto durationStdSwap = chrono::duration_cast<chrono::microseconds>(stopStdSwap - startStdSwap);
    cout << "Time taken to perform a std::swap: " << durationStdSwap.count() << " microseconds." << endl;

    return 0;
}
