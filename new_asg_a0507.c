#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
    int data;
    struct node * next;
};

struct node* InsertFirst(struct node * head, int no )
{
    struct node *newnode = (struct node * ) malloc( sizeof(struct node));

    if(newnode == NULL)
    {
        return NULL;
    }

    memset(newnode,0,sizeof(struct node));
    newnode->data=no;
    newnode->next=NULL;

    
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }

    return head;
}

struct node* delete_at_head(struct node *head)
{
    struct node *temp;
    temp = head;
    head = (head)->next;
    free(temp);
 
    return head;
}

void Display(struct node * head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}


int main()
{
    struct node *head = NULL;
    head = InsertFirst(head,10);
    head = InsertFirst(head,20);
    head = InsertFirst(head,30);
    head = InsertFirst(head,40);
    head = InsertFirst(head,50);
    Display(head);
    head = delete_at_head(head);
    printf("\n");
    Display(head);
    printf("\n");
    return 0;
}
