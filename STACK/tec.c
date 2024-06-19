#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node * next;
};

struct Node*  CreatNodes(int data) {
    struct Node* new_Node =(struct Node*) malloc(sizeof (struct Node));
    new_Node->data = data;
    new_Node->next = NULL;

    return new_Node;
}

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = CreatNodes(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
        new_node->next = *head_ref;
    }
}





void printList(struct Node* head) {
    printf("Nodes:");
    struct Node* curren = head;
    while (head != NULL) {
        printf(" %d",curren->data);
        curren = curren->next;
    }
    printf("\n");
}





int main() {
    struct  Node* head = NULL;

    insert(head,1);
    insert(head,1);
    insert(head,1);


    printList(&head);
}