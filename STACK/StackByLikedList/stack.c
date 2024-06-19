#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (top == NULL)
        newNode->next = NULL;
    else {
        newNode->next = top;
    }
    top = newNode;
    printf("pushed to stack: %d\n", data);
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty !! \n");
    } else {
        struct Node* temp = top;
        printf("Popped item: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
    return 0;
}

void isEmpty() {
    if( top == NULL) {
        printf("Stack is empty.");
    } else {
        printf("Stack is not empty.");
    }

}

void printStack() {
    struct Node* current = top;
    printf("Stack Items:");
    while (current != NULL) {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    printStack();
    pop();
    pop();
    pop();


    isEmpty();

    return 0;
}
