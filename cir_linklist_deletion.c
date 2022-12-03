#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *link;
};
struct list *creation(struct list *head)
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    if (new != NULL)
    {
        printf("Enter data\t");
        scanf("%d", &new->data);
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
            new->link = head;
        }
        else
        {
            temp = head;
            while (temp->link != head)
            {
                temp = temp->link;
            }
            temp->link = new;
            new->link = head;
        }
    }
    else
    {
        printf("No memory\t");
    }
    return head;
}
void traverse(struct list *head)
{
    struct list *temp;
    if (head != NULL)
    {
        temp = head;
        while (temp->link != head)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("%d\t", temp->data);
        printf("%d\t", temp->link->data);
    }
}
struct list *delete_1st(struct list *head)
{
    struct list *temp, *last;
    temp = head;
    last = head;
    while (last->link != head)
    {
        last = last->link;
    }
    head = temp->link;
    last->link = head;
    free(temp);
    return head;
}
struct list *delete_last(struct list *head)
{
    struct list *temp,*last;
    temp=head;
    while (temp->link!=head)
    {
        last=temp;
        temp=temp->link;
    }
    last->link=head;
    free(temp);
    return head;
}
struct list *delete_pos(struct list *head){
    struct list *prev,*temp;
    int count=0,pos;
    printf("Enter position\t");
    scanf("%d",&pos);
    temp=head;
    while (count<pos-1)
    {
        prev=temp;
        temp=temp->link;
        count++;
    }
    prev->link=temp->link;
    free(temp);
    return head;
}
void main()
{
    int c;
    struct list *head = NULL, *temp;
    while (1)
    {
        printf("Enter 1 for creation\t 2 for traversal\t 3 for delete 1st \t 4 for delete last\t 5 for delete pos\t 6 for exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = creation(head);
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            head = delete_1st(head);
            break;
        case 4:
            head = delete_last(head);
            break;
        case 5:
            head = delete_pos(head);
            break;
        case 6:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}