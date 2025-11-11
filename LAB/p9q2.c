#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("%d inserted at end.\n", value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    printf("%d inserted at end.\n", value);
}

void insertBeforePosition(int pos, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL || pos <= 1) {
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        printf("%d inserted before position %d (at beginning).\n", value, pos);
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted before position %d.\n", value, pos);
}

void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        printf("First node deleted.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);

    printf("First node deleted.\n");
}

void deleteAfterPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp->next != head && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        printf("No node exists after position %d.\n", pos);
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == head)
        head = delNode->next;

    free(delNode);
    printf("Node after position %d deleted.\n", pos);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert Before Position\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Node After Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeforePosition(pos, value);
                break;
            case 3:
                deleteFirstNode();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAfterPosition(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
