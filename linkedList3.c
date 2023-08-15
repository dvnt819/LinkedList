#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void printData(struct Node *head)
{
    struct Node * ptr=head;
    while(ptr!=NULL)
    {
        printf("element : %d \n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *deletBetween(struct Node *head,int index)
{
    struct Node *ptr=head;
    int i=0;
    while(i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    struct Node *q=ptr->next;
    ptr->next=q->next;
    free(q);
    return head;
}
struct Node *deletEnd(struct Node *head)
{
    struct Node *ptr=head;
    struct Node *q=ptr->next;
    while(q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
struct Node *deletFirst(struct Node *head)
{
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *second=(struct Node *)malloc(sizeof(struct Node));
    struct Node *third=(struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));
   
    head->data=23;
    head->next=second;

    second->data=34;
    second->next=third;

    third->data=45;
    third->next=fourth;

    fourth->data=56;
    fourth->next=NULL;

    printf("\nbefore deletion\n");
    printData(head);  

    printf("\nafter first deletion\n");
    head=deletFirst(head);
    printData(head);

    printf("\nafter inbetween deletion\n");
    head=deletBetween(head,1);
    printData(head);
    
    printf("\nafter end deletion\n");
    head=deletEnd(head);
    printData(head);
    return 0;
}
