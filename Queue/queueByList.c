#include <stdio.h>
#define MAX_SIZE 100 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to add an element to the queue (enqueue)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("Element %d enqueued\n", data);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1; // Reset queue if only one element
    } else {
        front++;
    }
    printf("Element %d dequeued\n", data);
    return data;
}

// Function to print the queue elements
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue(); // Output: Queue elements: 10 20 30

    dequeue();
    dequeue();
    dequeue();

    printQueue(); // Output: Queue elements: 20 30

    return 0;
}
