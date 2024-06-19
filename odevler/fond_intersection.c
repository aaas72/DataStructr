#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node * next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    return ptr1;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}



int main(){
    struct Node *list_1 = newNode(1);
    list_1->next = newNode(2);
    list_1->next->next = newNode(3);

    struct Node *list_2 = newNode(4);
    list_2->next = newNode(5);
    list_2->next->next = newNode(6);



    printf("List 1: ");
    printList(list_1);
    printf("List 2: ");
    printList(list_2);


    list_2->next->next = list_1->next; // هنا ننشاء التقاطع

    struct Node *intersection = findIntersection(list_1, list_2);
    if (intersection != NULL) {
        printf("Intersection found at node with value: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }


    return 0;
}
