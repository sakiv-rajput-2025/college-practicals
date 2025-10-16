#include <iostream>
using namespace std;

#define MAX 100 

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    int arr[100], n;
    Stack s;

    cout << "Enter number of elements in array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = s.pop();
    }

    cout << "\nArray after reversing using stack:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
