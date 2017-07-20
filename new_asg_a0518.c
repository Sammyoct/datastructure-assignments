/*add_at_middle*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
void Display(struct node * head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
struct node* get_common_elements(struct node *head, struct node *head1){
    struct node *head2 = NULL;
    struct node *temp1,*temp;
    temp = head;
    temp1 = head1;
    while(temp != NULL){
        while(temp1 != NULL){
            if(temp1->data==temp->data){
                head2 = InsertFirst(head2,temp->data);
            }
            temp1 = temp1->next;
            if(temp1 == NULL && temp !=NULL){
                temp1= head1;
            }else{
                break;
            }
        }
        temp = temp->next;
    }
    return head2;
}
int main()
{
    struct node *head = NULL;
    head = InsertFirst(head,10);
    head = InsertFirst(head,20);
    head = InsertFirst(head,30);
    head = InsertFirst(head,40);
    head = InsertFirst(head,50);
    printf("\n");
    Display(head);
    struct node *head1 = NULL;
    head1 = InsertFirst(head1,10);
    head1 = InsertFirst(head1,120);
    head1 = InsertFirst(head1,30);
    head1 = InsertFirst(head1,140);
    head1 = InsertFirst(head1,150);
    printf("\n");
    Display(head1);
    printf("\n");
    struct node *head2 = NULL;
    head2 = get_common_elements(head ,head1);
    Display(head2);
    printf("\n");
    return 0;
}
