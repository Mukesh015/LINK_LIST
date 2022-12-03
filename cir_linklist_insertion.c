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
        temp = head;
        while (temp->link != head)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("%d\t", temp->data);
        printf("%d\t", temp->link->data);
    }
    else
    {
        printf("No memory\n");
    }
}
struct list *insert_1st(struct list *head)
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter item\t");
    scanf("%d", &new->data);
    new->link = NULL;
    temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    new->link = head;
    temp->link = new;
    head = new;
    return head;
}

struct list *insert_last(struct list *head)
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter item\t");
    scanf("%d", &new->data);
    temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = new;
    new->link = head;
    return head;
}
struct list *insert_pos(struct list *head)
{
    struct list *new, *temp;
    int pos, count = 0;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter item\t");
    scanf("%d", &new->data);
    printf("Enter position\t");
    scanf("%d", &pos);
    temp = head;
    while (count < pos-2)
    {
        temp = temp->link;
        count++;
    }
    new->link = temp->link;
    temp->link = new;
    return head;
}
void main()
{
    int c;
    struct list *head = NULL, *temp;
    while (1)
    {
        printf("Enter 1 for creation\t2 for traverse\t3 for insert 1st\t4 for insert last\t5 for insert pos\t6 for exit\n");
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
            head = insert_1st(head);
            break;
        case 4:
            head = insert_last(head);
            break;
        case 5:
            head=insert_pos(head);
            break;
        case 6:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}