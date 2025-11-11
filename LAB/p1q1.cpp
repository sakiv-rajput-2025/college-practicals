#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value, choice;

    cout << "Enter number of elements in array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before operation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nChoose operation:\n1. Insert\n2. Delete\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter position to insert (1 to " << n+1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > n + 1) {
                cout << "Invalid position!";
                return 0;
            }
            cout << "Enter value to insert: ";
            cin >> value;

            for (int i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = value;
            n++;
            cout << "Array after insertion: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;

        case 2:
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;
            if (pos < 1 || pos > n) {
                cout << "Invalid position!";
                return 0;
            }

            for (int i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            cout << "Array after deletion: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
