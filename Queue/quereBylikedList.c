#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element %d enqueued\n", data);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int data = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL; // Reset queue if only one element
    }
    free(temp);
    printf("Element %d dequeued\n", data);
    return data;
}

// Function to print the queue elements
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue(); // Output: Queue elements: 10 20 30

    dequeue();
    printQueue(); // Output: Queue elements: 20 30

    return 0;
}
