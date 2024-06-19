#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printFromFirst(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
        if(current == head) // Check if we reached the starting point
            break;
    }
    printf("\n");
}

void printFromEnd(struct Node* end) {
    struct Node* current = end;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
        if(current == end) // Check if we reached the starting point
            break;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    struct Node* current = head;
    struct Node* first = head; // Keep track of the first node

    for (int i = 2; i <= 5; ++i) {
        struct Node* newNodePtr = newNode(i);
        current->next = newNodePtr;
        newNodePtr->prev = current;
        current = newNodePtr;
    }

    // Make the list circular
    current->next = first;
    first->prev = current;

    printf("Forward: ");
    printFromFirst(head);

    printf("Backward: ");
    printFromEnd(current);

    return 0;
}
