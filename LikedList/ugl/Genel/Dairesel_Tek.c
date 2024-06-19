#include <malloc.h>
#include "stdio.h"


struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* node =(struct Node*) malloc(sizeof (struct Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

void insert(struct Node** head_ref, int data) { // اتشير الى اخر عقده واذا كانت هي فارغة اجعلها تشير الى اول عقده
    struct Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref){
            last = last->next;
            last->next = new_node;
            new_node->next = *head_ref;
        }
    }
}
void printList(struct Node* head) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}


int main(){
    struct  Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    printf("Circular Linked List: ");
    printList(head);
}