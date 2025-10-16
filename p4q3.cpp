#include <iostream>
#include <cstring>
#include <cctype> 
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!\n";
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int evaluatePostfix(string postfix) {
    Stack s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': { 
                    result = 1;
                    for (int j = 0; j < val2; j++) result *= val1;
                    break;
                }
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter postfix expression (single-digit operands only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result of postfix expression: " << result << endl;

    return 0;
}
