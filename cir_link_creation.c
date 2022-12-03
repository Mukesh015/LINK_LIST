#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *link;
};
struct list *creation(struct list *head)
{
    struct list *temp, *new;
    new = (struct list *)malloc(sizeof(struct list));
    if (new != NULL)
    {
        printf("Enter item\t");
        scanf("%d", &new->data);
        new->link = head;
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
        printf("NO memory\n");
    }
    return head;
}
void traverse(struct list *head)
{
    struct list *temp;
    if (head != NULL)
    {
        temp=head;
        while (temp->link!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("%d\t",temp->data);
        printf("%d\t",temp->link->data);
    }
    else{
        printf("No memory\n");
    }
}
void main()
{
    int c;
    struct list *head = NULL, *temp;
    while (1)
    {
        printf("Enter 1 for creation\t2 for traverse\t3 for exit\n");
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
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}