#include <malloc.h>
#include "stdio.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node * CreateNewNode(int data) {
    struct Node * new_node = (struct Node*)malloc(sizeof (struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void PrintItems(struct Node * node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct Node* AddMiddle(struct Node* head, int data, int position) {
    printf("After Addition:\n");
    struct Node* new_node = CreateNewNode(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node* current = head;
        int count = 1;
        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Position out of range\n");
            return head;
        }
        new_node->next = current->next;
        if (current->next != NULL) {
            current->next = new_node;
        }
        current->next = new_node;
    }
    return head;
}

int main() {
    struct Node * head = CreateNewNode(1);
    struct Node * current = head;

    int num_nodes = 5;
    for(int i = 2; i <= num_nodes; i++) {
        struct Node * new_node = CreateNewNode(i);
        current->next = new_node;
        current = current->next;
    }
    PrintItems(head);

    head = AddMiddle(head, 8,1);

    PrintItems(head);
}
