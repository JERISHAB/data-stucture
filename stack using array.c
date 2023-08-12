#include <stdio.h>
int a[100],size,top;
void push(int ele)
{
    if(top==size-1)
        printf("the stack is full\n");
    else
       {
           top++;
        a[top]=ele;
        printf("pushed successfully\n");
       }
}

void pop()
{
    if(top==-1)
        printf("Stack is empty\n");
    else
       {
           printf("\npoped element %d\n",a[top]);
        top--;
       }
}

void display()
{
    if(top==-1)
       { printf("stack is empty\n");}
    else
       {
           printf("the stack is \n");
             for(int i=0;i<=top;i++)
                printf("%d\t",a[i]);
       }        
}

void status()
{
    float free;
    if(top==-1)
        printf("stack is empty");
    else if (top==size-1)
        printf("stack is full");
    else
        {
            free=(float)(size-top-1)*100/size;
            printf("the free space is : %f ",free);
        }
}

void main()
{
    int n,choice;
    top=-1;
    printf("enter the size of stack");
    scanf("%d",&size);
    do
    {
        printf("\n 1.push\t2.pop\t3.display\t4.status\t5.exit");
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
            case 4:status();break;
            case 5:break;   
        }
    }while(choice!=5); 
}