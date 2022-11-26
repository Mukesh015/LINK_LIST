#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *link;
};
struct list *linklist_creation(struct list *head)
{
    int item;
    struct list *new,*temp;
    new=(struct list*)malloc(sizeof(struct list));
    
    if(new!=NULL){
    printf("Enter the item\t");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
    if (head==NULL)
    {
        head=new;
    }
    else
    {
        temp=head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
        }
    }
    else
    printf("No memory");
    return head;
}
void traverse(struct list *head)
{
    struct list *temp;
    
      if (head!=NULL)
      {
        temp=head;
      while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
      }
}

void main()
{
    int c;
    struct list *head=NULL,*temp;
    while (1)
    {
        printf("Enter 1 for creation");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
         
        head=linklist_creation(head);
        break;
        case 2: traverse(head);
        break;
        case 3:printf("Program end");
        exit(0);
        default:printf("Wrong choice");
        }
    }
}