#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int num) {
    if (num == 0)
        return 1;
    return (int)log10(abs(num)) + 1; 
}

int main() {
    int arr[10];

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (countDigits(arr[j]) > countDigits(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nArray sorted by number of digits:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
