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
struct list *delete_1st()
{
    struct list *temp;
    temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
    return head;
}
struct list *delete_last()
{
    struct list *temp_1, *temp_2;
    temp_1 = head;
    while (temp_1->next != NULL)
    {
        temp_2 = temp_1;
        temp_1 = temp_1->next;
    }
    temp_2->next = NULL;
    free(temp_1);
    return head;
}
struct list *delete_pos()
{
    struct list *temp_1, *temp_2;
    int pos, count = 0;
    printf("Enter position\t");
    scanf("%d", &pos);
    temp_1 = head;
    while (count < pos - 1)
    {
        temp_2 = temp_1;
        temp_1 = temp_1->next;
        count++;
    }
    temp_2->next = temp_1->next;
    temp_1->next->prev = temp_2;
    free(temp_1);
    return head;
}
void main()
{
    int c;
    struct list *temp;
    while (1)
    {
        printf("Enter ---> 1 for creation\t 2 for forward traverse\t 3 for backward traverse\t 4 for delete 1st\t 5 for delete last\t 6 for delete pos\t 7 for exit\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = creation();
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            traverse_bck(tail);
            break;
        case 4:
            head = delete_1st();
            break;
        case 5:
            head = delete_last();
            break;
        case 6:
            head = delete_pos();
            break;
        case 7:
            printf("Program end");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}