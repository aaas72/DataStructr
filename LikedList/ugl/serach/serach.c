#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* first_node = NULL;
struct Node* CreatNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void Ekle(int data) {
    struct Node* new_node = CreatNode(data);
    if (first_node == NULL) {
        first_node = new_node;
    } else {
        struct Node* temp = first_node;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void nodeNums() {
    int control = 0, timer = 0;
    if (first_node == NULL) {
        printf("Eleman yok \n");
    } else {
        struct Node* temp = first_node;
        while (temp != NULL) {
            timer += 1;
            control = 1;
            temp = temp->next;
        }
        if (control == 1) {
            printf("%d elelmen vardir: \n", timer);
        }
    }
}
int main() {
    Ekle(1);
    Ekle(2);

    nodeNums();

    return 0;
}
