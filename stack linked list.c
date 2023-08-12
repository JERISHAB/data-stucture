#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top;

void display()
{
    struct node *curr;
    if(top==NULL)
        printf("stack is empty");
    else
        {
            printf("\nthe stack is : ");
            curr=top;
            while(curr!=NULL)
            {
                printf("%d\t",curr->data);
                curr=curr->next;
            }
        }
}

void push(int ele)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data=ele;
    new->next=top;
    top=new;
    printf("push successfull\n");
}

void pop()
{
    if(top==NULL)
        printf("Stack is empty\n");
    else
        {
            struct node *temp;
            printf("poped %d ",top->data);
            temp=top;
            top=top->next;
            free(temp);
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
                    printf("enter the number to be pushed");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2:pop();break;
            case 3:display();break;
            case 4:break;   
        }
    }while(choice!=4); 
}
