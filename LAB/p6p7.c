#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory not allocated.\n");
            break;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
    printf("\nList created successfully.\n");
}

void traverse() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtFront(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at front.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at end.\n");
}

void insertAtPosition(int data, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i;

    newNode->data = data;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}

void deleteFront() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    printf("Front node deleted.\n");
}

void deleteEnd() {
    struct Node *temp = head, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

void deletePosition(int pos) {
    struct Node *temp = head, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
        return;
    }

    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);
}

void reverseLL() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("Linked list reversed.\n");
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create List\n");
        printf("2. Traverse\n");
        printf("3. Insert at Front\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete Front\n");
        printf("7. Delete End\n");
        printf("8. Delete from Position\n");
        printf("9. Reverse Linked List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPosition(data, pos);
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 9:
                reverseLL();
                break;
            case 10:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
