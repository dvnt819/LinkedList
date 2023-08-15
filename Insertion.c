#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node *insertAt(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i=i+1;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node *insertEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next= NULL;
    return head;
}
void printData(struct Node *ptr)
{
    while (ptr != 0)
    {
        printf("element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 44;
    head->next = second;

    second->data = 33;
    second->next = third;

    third->data = 77;
    third->next = NULL;

    printf("before adding new node\n");
    printData(head);

    head = insertFirst(head, 89);
    printf("\nafter adding new node at start\n");
    printData(head);

    head = insertAt(head, 99 , 2);
    printf("\nafter adding new node at given index\n");
    printData(head);

    head = insertEnd(head,106);
    printf("\nafter adding new node at end\n");
    printData(head);
    return 0;
}
