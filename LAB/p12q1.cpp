#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key, choice;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\n1. Linear Search\n2. Binary Search\nEnter your choice: ";
    cin >> choice;

    int result;

    if (choice == 1) {
        result = linearSearch(arr, n, key);
        if (result != -1)
            cout << "Element found at position " << result + 1 << endl;
        else
            cout << "Element not found.\n";
    } 
    else if (choice == 2) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        result = binarySearch(arr, n, key);
        if (result != -1)
            cout << "Element found at position " << result + 1 << " (after sorting)\n";
        else
            cout << "Element not found.\n";
    } 
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
