#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;
 node *head,*tail,*curr;
 node *p;
 void insertfirst(int ele)
 {
     p=(node *)malloc(sizeof(node));
     p->data=ele;
     p->prev=NULL;
     p->next=head;
     if(head==NULL)
        head=tail=p;
    else
    {
       head->prev=p;
       head=p;
    }
 }
 
 void insertlast(int ele)
 {
     p=(node *)malloc(sizeof(node));
     p->data=ele;
     p->next=NULL;
     if(head==NULL)
        head=tail=p;
    else
        {
            tail->next=p;
            p->prev=tail;
            tail=p;
        }
 }
 
 void insertbefore(int ele,int val)
 {
      p=(node *)malloc(sizeof(node));
      p->data=ele;
      curr=head;
      while(curr!=NULL&&curr->data==val)
        curr=curr->next;
    if(curr==NULL)
        printf("no such node");
    else
        {
            p->next=curr;
            p->prev=curr->prev;
            if(curr->prev==NULL)
                head=p;
            else
                curr->prev->next=p;
            curr->prev=p;    
        }
 }
 
 void insertafter(int ele,int val)
 {
     p=(node *)malloc(sizeof(node));
      p->data=ele;
      curr=head;
      while(curr!=NULL&&curr->data!=val)
        curr=curr->next;
    if(curr==NULL)
        printf("no such node");
    else
        {
            p->prev=curr;
            p->next=curr->next;
            if(curr->next==NULL)
                tail=p;
            else
                curr->next->prev=p;
            curr->next=p ;       
        }
 }
 
 void delete(int ele)
 {
     curr=head;
     while(curr!=NULL&&curr->data!=ele)
            curr=curr->next;
     if(curr==NULL)
        printf("NOT POSSIBLE");
    else
        {
            if(curr->prev==NULL)
                head=curr->next;
            else
                curr->prev->next=curr->next;
            if(curr->next==NULL)
                tail=curr->prev;
            else
                curr->next->prev=curr->prev;
                free(curr);
        }
            
 }
 
 
void display()
{
    printf("Elements in List are: ");
    curr=head;
    while (curr!=NULL)
    {
    printf("%d \t",curr->data);
    curr=curr->next;
    }
}

void main()
{
    int ch,ele,val;
    do
    {
    printf("\n\nChoose:\n1.Insert_First\n2.Insert_Last\n3.Insert_Before\n4.Insret_After\n5.Delete_node\n6.Display\n7.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("Enter the number to insert: ");
                scanf("%d",&ele);
                insertfirst(ele);
                break;
        case 2: printf("Enter the number to insert: ");
                scanf("%d",&ele);
                insertlast(ele);
                break;
        case 3: printf("Enter the number to insert: ");
                scanf("%d",&ele);
                printf("Enter the number to be consider: ");
                scanf("%d",&val);
                insertbefore(ele,val);
                break;
        case 4: printf("Enter the number to insert: ");
                scanf("%d",&ele);
                printf("Enter the number to be consider: ");
                scanf("%d",&val);
                insertafter(ele,val);
                break;
        case 5: printf("Enter the number to deleted: ");
                scanf("%d",&ele);
                delete(ele);
                break;
        case 6: display();
                break;
        case 7: break;
        default: printf("INVALID");
        }
    }while(ch!=7);
}
