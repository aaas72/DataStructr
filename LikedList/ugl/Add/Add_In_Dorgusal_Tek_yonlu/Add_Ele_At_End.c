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
struct Node* AddALast(struct  Node * head, int data) {
    printf("After Addition:\n");
    struct Node * new_node = CreateNewNode(data);
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL) {
        new_node = head;
        new_node->next = NULL;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
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

    head = AddALast(head, 8); // تحديث Head بعد الاضافه

    PrintItems(head);
}
