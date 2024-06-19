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
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);  // تحرير العقده الاولى
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
    head= deleteFirstNode(head);
    PrintItems(head);
}
