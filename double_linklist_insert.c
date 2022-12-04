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
    struct list *new, *temp;
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
void traverse_fwd(struct list *head)
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
void traverse_bcw(struct list *tail)
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
struct list *insert_1st()
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter data\t");
    scanf("%d", &new->data);
    temp = head;
    new->next = temp;
    temp->prev = new;
    head = new;
    return head;
}
struct list *insert_last()
{
    struct list *new, *temp;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter data\t");
    scanf("%d", &new->data);
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    new->next = NULL;
    return head;
}
struct list *insert_pos()
{
    struct list *new, *temp;
    int pos, count = 0;
    new = (struct list *)malloc(sizeof(struct list));
    printf("Enter data\t");
    scanf("%d", &new->data);
    printf("Enter position\t");
    scanf("%d", &pos);
    temp = head;
    while (count < pos - 2)
    {
        temp = temp->next;
        count++;
    }
    new->next = temp->next;
    temp->next->prev = new;
    temp->next = new;
    new->prev = temp;
    return head;
}
void main()
{
    int c;
    struct list *temp;
    while (1)
    {
        printf("Enter ---> 1 for creation\t 2 for forward traverse\t 3 for backward traverse\t 4 for insert 1st\t 5 for insert last\t 6 for insert pos\t 7 for exit\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = creation();
            break;
        case 2:
            traverse_fwd(head);
            break;
        case 3:
            traverse_bcw(tail);
            break;
        case 4:
            head = insert_1st(head);
            break;
        case 5:
            head = insert_last(head);
            break;
        case 6:
            head = insert_pos(head);
            break;
        case 7:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}