#include <iostream>

using namespace std;

void print_num(int& num) {
    cout << "lvalue: " << num << endl;
}

void print_num(int&& num) {
    cout << "rvalue: " << num << endl;
}

int main() {
    int num = 10;

    print_num(num);
    print_num(100);
    print_num(100 + 100);
    print_num(num + 100);
    print_num(num++);
    print_num(++num);

    return 0;
}
