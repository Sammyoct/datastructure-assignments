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

int count_node(struct node* head)
{
    int i = 1;
    while(head->next != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

int find_middle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    if (head!=NULL)
    {
      while (fast_ptr != NULL && fast_ptr->next != NULL)
      {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
      }
      printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
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
    printf("\n");
    Display(head);
    find_middle(head);
    return 0;
}
