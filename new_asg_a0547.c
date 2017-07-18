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

/* Function to delete at head*/
struct node* delete_at_head(struct node *head)
{
    struct node *temp;
    temp = head;
    head = (head)->next;
    free(temp);
 
    return head;
}

/* Function to add node at tail of list */
struct node* add_at_tail(struct node *head, int val)
{
    struct node *temp= head;
    struct node * newnode = (struct node * )malloc (sizeof(struct node));
    memset(newnode,0, sizeof(struct node ));
    newnode->next=NULL;
    newnode->data=val;
    if(head == NULL)
    {
        printf("Node list is empty");
    }
    else
    {
        while(temp->next != NULL)
        {
            temp= temp->next;
        }
    }
    temp ->next =newnode;
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
    add_at_tail(head, 100);
    Display(head);
    return 0;
}
