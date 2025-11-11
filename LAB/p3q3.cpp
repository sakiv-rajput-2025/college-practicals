#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100  

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!\n";
        } else {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return '\0';
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    char str[100];
    Stack s;

    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    char rev[100];
    for (int i = 0; i < len; i++) {
        rev[i] = s.pop();
    }
    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        cout << "\nThe string \"" << str << "\" is a palindrome.\n";
    else
        cout << "\nThe string \"" << str << "\" is NOT a palindrome.\n";

    return 0;
}
