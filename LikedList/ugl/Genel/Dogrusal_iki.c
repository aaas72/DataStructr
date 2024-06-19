// Doğrusal <Liked list> iki yönlü

#include <malloc.h>
#include "stdio.h"

struct  Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreactNodes(int data) {
    struct Node* node = (struct Node*)malloc(sizeof (struct Node));
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void printListFromFirst(struct Node* first_noed) {
    printf("Printing list from first: \n");
    struct Node * current = first_noed;
    while (current != NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}

void printListFromEnd(struct Node* end_noed) {
    printf("Printing list from end: \n");
    struct Node * current = end_noed;
    while (current != NULL){
        printf("%d\n",current->data);
        current = current->prev;
    }
}
int main() {
    struct Node * head = CreactNodes(1);
    struct Node * current = head;

    int num_nodes = 5; // عدد العقد المراد طباعتها
    for (int i = 2; i <num_nodes; ++i) {
        struct Node* new_node = CreactNodes(i);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
    }

    printListFromFirst(head);
    printListFromEnd(current);

}