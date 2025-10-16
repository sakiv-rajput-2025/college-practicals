#include <iostream>
using namespace std;

void callByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "\nInside callByValue function: a = " << a << ", b = " << b;
}

void callByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "\nInside callByReference function: a = " << a << ", b = " << b;
}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\nBefore swapping: x = " << x << ", y = " << y;

    callByValue(x, y);
    cout << "\nAfter callByValue: x = " << x << ", y = " << y;

    callByReference(x, y);
    cout << "\nAfter callByReference: x = " << x << ", y = " << y << endl;

    return 0;
}
