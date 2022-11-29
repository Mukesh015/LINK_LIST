#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *link;
};

void traversal(struct list *head)
{
    struct list *temp;
    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}

struct list *creation(struct list *head)
{
    struct list *temp, *new;
    int item;
    new = (struct list *)malloc(sizeof(struct list));
    if (new != NULL)
    {
        printf("Enter item\t");
        scanf("%d", &item);
        new->data = item;
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
        }
    }
    else
    {
        printf("No memory");
    }
    return head;
}
struct list *insertion_1st(struct list *head)
{
    struct list *new;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter item\t");
    scanf("%d", &new->data);
    new->link = head;
    head = new;
    return head;
}
void insertion_pos(struct list *head)
{
    struct list *new, *temp;
    int pos, count = 0;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter the position\t");
    scanf("%d", &pos);
    printf("Enter item\t");
    scanf("%d", &new->data);
    if (count > pos)
    {
        printf("Wrong input");
    }
    else
    {
        temp = head;
        while (temp->link!=NULL)
        {
            count++;
            if(count==pos-1)
            break;
            temp = temp->link;
        }
    }
    new->link = temp->link;
    temp->link = new;
}

struct list *insertion_last(struct list *head)
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter item\t");
    scanf("%d", &new->data);
    new->link = NULL;
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return head;
}
void main()
{
    int c;
    struct list *head = NULL, *temp;
    while (1)
    {
        printf("Enter 1 for creation\t 2 for traversal\t 3 for insert 1st \t 4 for insert last\t 5 for insert pos\t 6 for exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = creation(head);
            break;
        case 2:
            traversal(head);
            break;
        case 3:
            head = insertion_1st(head);
            break;
        case 4:
            head = insertion_last(head);
            break;
        case 5:
            insertion_pos(head);
            break;
        case 6:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong input");
        }
    }
}