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
struct Node* insertAtLast(struct Node* head, int data) {
    if (head == NULL) {
        struct Node* new_node = CreactNodes(data);
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    } else {
        struct Node* new_node = CreactNodes(data);
        new_node->data = data;
        new_node->next = NULL;
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
    return head;
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

    head = insertAtLast(head, 7); // تحديث Head بعد الاضافه
    while (current->next != NULL) {
        current = current->next;
    }
    printf("---------------\nAfter Addition:\n---------------\n");
    printListFromFirst(head);
    printListFromEnd(current);


}