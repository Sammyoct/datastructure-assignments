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
struct node * compare(struct node *head,struct node *head1)
{
    struct node *temp = head;
    struct node *temp1 = head1;
    if(head == NULL){
        printf("One of the link list is empty");
        return 0;
    }else{
        while(temp->next!=NULL)
        {
            if(temp->data != temp1->data){
                printf("Both are not equal");
                return 0;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        printf("Both lists are equal");
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
    struct node *head1 = NULL;
    head1 = InsertFirst(head1,10);
    head1 = InsertFirst(head1,20);
    head1 = InsertFirst(head1,30);
    head1 = InsertFirst(head1,40);
    head1 = InsertFirst(head1,50);
    printf("\n");
    Display(head1);
    printf("\n");
    compare(head,head1);
    printf("\n");
    return 0;
}
