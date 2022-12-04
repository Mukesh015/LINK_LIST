#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
    struct list *prev;
};
struct list *head = NULL, *tail = NULL;
struct list *creation()
{
    struct list *temp;
    struct list *new;
    new = (struct list *)malloc(sizeof(struct list));
    if (new != NULL)
    {
        printf("Enter data\t");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = NULL;
        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->prev = temp;
            tail = new;
        }
    }
    else
    {
        printf("No memory\n");
    }
    return head;
}
void traverse(struct list *head)
{
    int item;
    struct list *temp;
    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void traverse_bck(struct list *tail)
{
    int item;
    struct list *temp;
    if (tail != NULL)
    {
        temp = tail;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->prev;
        }
    }
}
void main()
{
    int c;
    struct list *temp;
    while (1)
    {
        printf("Enter 1 for creation");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = creation();
            break;
        case 2:
            traverse(head);
            break;
        case 4:
            traverse_bck(tail);
            break;
        case 3:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}