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

struct node* delete_at_particular_position(struct node *head, int pos)
{
    struct node *temp, *prev;
    temp = head;
    int i = 0;

    if(head == NULL)
    {
        printf("Node list is empty");
    }else{
        for(i=1;i<pos;i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;

        return head;
    }
}

int count_node(struct node* head)
{
    int i = 0;
    while(head->next != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

struct node* delete_at_middle(struct node *head)
{
    int count;
    int pos=0;
    count = count_node(head);
    printf("\n");
    printf("%d",count);
    printf("\n");
    if((count % 2)== 0){
        pos = count/2;
        head = delete_at_particular_position(head,pos+1);
    }else if((count % 3) == 0){
        pos = count/3;
        head = delete_at_particular_position(head,pos+1);
    }else{
        int i;
        i = count/2;
        pos = round(i);
        head = delete_at_particular_position(head,pos);
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
    head = delete_at_middle(head); 
    printf("\n");
    Display(head);
    return 0;
}
