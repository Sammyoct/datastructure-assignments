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

struct node* add_at_particular_position(struct node *head, int pos, int n)
{
    struct node *temp = head;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    memset(newnode,0,sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if(head == NULL)
    {
        printf("Node list is empty");
    }else{
        for(i=1;i<pos;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
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

struct node* add_at_middle(struct node *head, int n)
{
    int count;
    int pos=0;
    count = count_node(head);
    printf("%d",count);
    if((count % 2)== 0){
        pos = count/2;
        head = add_at_particular_position(head,pos+1,n);
    }else if((count % 3) == 0){
        pos = count/3;
        head = add_at_particular_position(head,pos+1,n);
    }else{
        int i;
        i = count/2;
        pos = round(i);
        head = add_at_particular_position(head,pos,n);
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
    head = delete_at_head(head);
    printf("\n");
    Display(head);
    printf("\n");
    add_at_tail(head, 100);
    Display(head);
    printf("\n");
    head = add_at_particular_position(head,2,33);
    printf("\n");
    Display(head);
    printf("\n");
    head = add_at_middle(head,22);
    printf("\n");
    Display(head);
    return 0;
}
