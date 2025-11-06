#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory not allocated)\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

int isFull() {
    struct Node* test = (struct Node*)malloc(sizeof(struct Node));
    if (test == NULL)
        return 1;
    free(test);
    return 0;
}

struct Node* push(struct Node* top, int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return top;
    }
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
    return top;
}

struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack Underflow! Cannot pop.\n");
        return top;
    }
    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

void peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. ISEMPTY\n5. ISFULL\n6. DISPLAY\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                if (isEmpty(top))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                if (isFull())
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 6:
                display(top);
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
