#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomString : public std::string {
public:
    // Inherit constructors from the base class
    using std::string::string;

    // Custom constructor
    CustomString(const char* str) : std::string(str) {
        std::cout << "CustomString constructor called: " << str << std::endl;
    }

    // Copy constructor
    CustomString(const CustomString& other) : std::string(other) {
        std::cout << "CustomString copy constructor called." << std::endl;
    }

    // Copy assignment operator
    CustomString& operator=(const CustomString& other) {
        std::cout << "CustomString copy assignment operator called." << std::endl;
        if (this != &other) {
            // Call the base class copy assignment operator
            std::string::operator=(other);
        }
        return *this;
    }

    // Move constructor
    CustomString(CustomString&& other) noexcept : std::string(std::move(other)) {
        std::cout << "CustomString move constructor called." << std::endl;
    }

    // Move assignment operator
    CustomString& operator=(CustomString&& other) noexcept {
        std::cout << "CustomString move assignment operator called." << std::endl;
        if (this != &other) {
            // Call the base class move assignment operator
            std::string::operator=(std::move(other));
        }
        return *this;
    }
};

void print_string(string& s) {
    cout << "This is lvalue: " << s << endl;
}

void print_string(string&& s) {
    cout << "This is rvalue: " << &s << endl;
}

int main()
{
    CustomString s = "qweqwe";
    print_string(s);
    print_string(CustomString("Rick"));

    cout << s.length() << endl;

    return 0;
}
