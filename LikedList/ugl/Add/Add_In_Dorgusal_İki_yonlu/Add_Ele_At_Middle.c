// Add_In_Dorgusal_İki_yonlu items At First in liked list
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
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void printListFromEnd(struct Node* end_noed) {
    printf("Printing list from end: \n");
    struct Node * current = end_noed;
    while (current != NULL){
        printf("%d ",current->data);
        current = current->prev;
    }
    printf("\n");
}
void insertBetweenNodes(struct Node* first_node, struct Node* second_node, int data) {
    if (first_node == NULL || second_node == NULL) {
        printf(" Not found Nodes\n");
        return;
    }

    struct Node* new_node = CreactNodes(data);

    new_node->next = second_node;
    new_node->prev = first_node;

    first_node->next = new_node;
    second_node->prev = new_node;
}


int main() {
    struct Node * head = CreactNodes(1);
    struct Node * current = head;

    int num_nodes = 6; // عدد العقد
    for (int i = 2; i <= num_nodes; ++i) {
        struct Node* new_node = CreactNodes(i);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
    }

    printListFromFirst(head);
    printListFromEnd(current);


    insertBetweenNodes(head,current, 7);
    printf("---------------\nAfter Addition:\n---------------\n");
    printListFromFirst(head);
    printListFromEnd(current);


}