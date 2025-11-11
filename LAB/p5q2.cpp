#include <iostream>
using namespace std;
#define MAX 5  

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }
            arr[rear] = value;
            cout << value << " enqueued to queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
        } else {
            cout << arr[front] << " dequeued from queue.\n";
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    while (true) {
        cout << "\n--- Circular Queue Operations Menu ---";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Check if Empty";
        cout << "\n4. Check if Full";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                if (cq.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 4:
                if (cq.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
