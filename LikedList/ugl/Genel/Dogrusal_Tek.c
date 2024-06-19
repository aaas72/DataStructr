#include <malloc.h>
#include "stdio.h"


struct Node {
    int data;
    struct Node* next;
};

int main () {
    struct Node* head  = NULL;
    struct Node* node1 = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    node1 = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));

    node1-> data = 1;
    node2-> data = 2;
    node3-> data = 3;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;


    printf("The Liked List :\n");
    head = node1;
    while (head != NULL){
        printf("%d \n",head->data);
        head = head->next;
    }
}