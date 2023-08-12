#include<stdio.h>
#define size 5
int F =-1, R =-1, Q[size];

int is_full()
{
    if(F==(R+1)%size)
        return(1);
    else
        return(0);
}

int is_empty()
{
    if(F==-1 && R==-1)
        return(1);
    else
        return(0);
}

void Insert_rare(int ele)
{
    R=(R+1)%size;
    if(F==-1)
         F=0;
    Q[R] = ele;
}

int Delete_front()
{
    int ele = Q[F];
    {
    if(F==R)
         F=R=-1;
    else
         F=(F+1)%size;
    }
    return (ele);
}

void Display()
{
    if(is_empty())
         printf("QUEUE EMPTY");
    else
    {
        int i;
        for(i=F;i!=R;i=(i+1)%size)
        printf("%d \t",Q[i]);
        printf("%d \t",Q[R]);
    }
}

void main()
{
    int ch,ele;
    printf("CIRCULAR QUEUE");
    do
    {
    printf("\n\nChoose:\n1.Insert\n2.Delete\n3.Isfull\n4.Isempty\n5.Display\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1: if(is_full())
                    printf("QUEUE FULL");
                else
                {
                    printf("\nEnter the number to be inserted:");
                    scanf("%d",&ele);
                    Insert_rare(ele);
                }
                break;
        case 2: if(is_empty())
                     printf("QUEUE IS EMPTY");
                else
                {
                    ele=Delete_front();
                    printf("The deleted element is %d",ele);
                }
                break;
        case 3: if(is_full())
                    printf("QUEUE FULL");
                else
                     printf("SPACE AVAILABLE");
                break;
        case 4: if(is_empty())
                    printf("QUEUE IS EMPTY");
                else
                    printf("MEMBERS OCCUPIED");
                break;
        case 5: printf("\nThe elements in the Queue :\n");
                Display();
                break;
        case 6: break;
        default : printf("\nINVALID");
        }
    }while(ch!=6);
}
