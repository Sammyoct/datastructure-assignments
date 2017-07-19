/*compare_two*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node 
{
    int data;
    struct node * next;
};

struct node* InsertFirst(struct node *head, int no)
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

void Display(struct node * head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
struct node * search_for_value(struct node *head, int n)
{
    struct node *temp = head;
    if(head == NULL){
        printf("One of the link list is empty");
        return 0;
    }else{
        while(temp->next!=NULL)
        {
            if(temp->data == n){
                printf("Found the value:%d",n);
                return 0;
            }
            temp = temp->next;
        }
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
    printf("\n");
    search_for_value(head,40);
    printf("\n");
    return 0;
}
