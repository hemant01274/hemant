#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* XOR(struct node *a, struct node *b) {
    return (struct node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
void insert(struct node **head, int data) {
    struct node *new1 = (struct node *) malloc(sizeof(struct node));
    new1->data = data;
    new1->link = XOR(*head, NULL);
    if (*head != NULL) {
        struct node* next = XOR((*head)->link, NULL);
        (*head)->link = XOR(new1, next);
    }
    *head= new1;
}
void display(struct node *head) {
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    printf("LINK LIST\n");
    while (curr != NULL) {
        printf("%d ", curr->data);
        next = XOR(prev, curr->link);
        prev = curr;
        curr = next;
    }
}
int main() {
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    display(head);
 
    return 0;
}
