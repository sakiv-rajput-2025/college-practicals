#include <iostream>
using namespace std;

#define MAX 100  

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char ch) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!\n";
        } else {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top == -1) {
            return '\0'; 
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (isOpening(ch)) {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() || !isMatching(s.pop(), ch)) {
                return false; 
            }
        }
    }

    return s.isEmpty(); 
}

int main() {
    string expr;

    cout << "Enter an expression with parentheses: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "The expression is balanced.\n";
    else
        cout << "The expression is NOT balanced.\n";

    return 0;
}
