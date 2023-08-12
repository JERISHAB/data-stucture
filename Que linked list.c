#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front,*rear;

void display()
{
    if(front==NULL)
        printf("queue is empty");
    else
        {
            struct node *curr;
            curr=front;
            printf("the queue is : ");
            while(curr!=NULL)
            {
                printf("%d\t",curr->data);
                curr=curr->next;
            }  
        }
}

void enque(int ele)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data=ele;
    new->next=NULL;
    if(front==NULL)
        front=rear=new;
    else
        {
            rear->next=new;
            rear=new;
        }
    printf("enque successfull");    
}

void deque()
{
    struct node *temp;
    if(front==NULL)
        printf("queue is empty");
    else
        {   
            temp=front;
            printf("deque %d ",temp->data );
            if(front==rear)
                front=rear=NULL;
            else
                front=front->next;
            free (temp);    
        }
}

void main()
{
     int n,choice;
    do
    {
        printf("\n 1.push\t2.pop\t3.display\t4.exit");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("enter the number to enq");
                    scanf("%d",&n);
                    enque(n);
                    break;
            case 2:deque();break;
            case 3:display();break;
            case 4:break;   
        }
    }while(choice!=4); 
}
