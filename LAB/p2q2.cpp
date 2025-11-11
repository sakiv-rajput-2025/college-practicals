#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    int *ptr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ptr = arr; 

    cout << "\nArray elements in reverse order:\n";
    for (int i = n - 1; i >= 0; i--) {
        cout << *(ptr + i) << " ";
    }

    cout << endl;
    return 0;
}
