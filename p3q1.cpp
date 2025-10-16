#include <iostream>
using namespace std;
#define MAX 5  

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; 
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Operations Menu ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Check if Empty";
        cout << "\n5. Check if Full";
        cout << "\n6. Display";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
