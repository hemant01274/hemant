#include<stdio.h>
#include<conio.h>
#include<malloc.h> 
struct node
{
    int data;
    struct node* next;
};
struct node* push(struct node *s,int data);
struct node* pop(struct node *s,int *data);
void display(struct node* head);
int main()
{
    struct node* head = NULL;
    int size, element;
    int count = 0;
 
    printf("Enter the number of elements:");
    scanf("%d",&size);
 
    printf("Push elements into the stack\n");
    while(count < size)
    {
 
        printf("Enter a number to push into the stack:");
        scanf("%d",&element);
        head = push(head,element);
        display(head);
        count++;
    }
 
    printf("Pop elements from the stack\n");
    while(head!= NULL)
    {
        head = pop(head,&element);
        printf("Pop %d from stack\n",element);
        display(head);
    }
 
    return 0;
}
struct node* push(struct node* head,int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("stack is full\n");
    }
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}
struct node* pop(struct node *head,int *element)
{
    struct node* tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}
void display(struct node* head)
{
    struct node *curr;
    curr = head;
    if(curr!= NULL)
    {
        printf("Stack: ");
        do
        {
            printf("%d ",curr->data);
            curr = curr->next;
        }
        while (curr!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
 
}
