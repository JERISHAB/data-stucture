#include<stdio.h>
#include<stdlib.h>
 struct node
  { 
      int data;
     struct node *link;
  };
 struct node *head;
 
 void display()
 {
     struct node *ptr;
     if(head==NULL)
        printf("\n linked list is empty");
    else
    {
        ptr=head;
        printf("\n linked list elements are :");
        while(ptr!=NULL)
            {
                printf("%d\t",ptr->data);
                ptr=ptr->link;
            }
    }
 }
 
 void insertfront(int x)
 {
     struct node *new;
     new= (struct node *)malloc(sizeof(struct node));
     new->data=x;
     new->link=head;
     head=new;
     display();
 }
 
 void insertend(int x)
 {
     struct node *ptr,*new;
     new= (struct node *)malloc(sizeof(struct node));
     new->data=x;
     new->link=NULL;
     if(head==NULL)
        head=new;
    else
        {
            ptr=head;
            while(ptr->link!=NULL)
                ptr=ptr->link;
            ptr->link=new;
        }
        display();
 }

void insertafter(int key,int x)
{
    struct node *new,*ptr;
    if(head==NULL)
        printf("search key not found insertion not possilble");
    else
        {
            ptr=head;
            while(ptr->data!=key&&ptr->link!=NULL)
                ptr=ptr->link;
            if(ptr->data!=key)
                printf("search key not found insertion not possilble");
            else
                {
                     new= (struct node *)malloc(sizeof(struct node));
                     new->data=x;
                     new->link=ptr->link;
                     ptr->link=new;
                }
        }
        display();
}

void deletefront()
{
    struct node *temp;
     if(head==NULL)
        printf("list is empty. deletion not possible");
    else 
        {
            temp=head;
            head=head->link;
            free(temp);
        }
        display();
}

void deleteend()
{
    struct node *pre,*curr,*temp;
    if(head==NULL)
        printf("list is empty. deletion not possible");
    else if(head->link==NULL)
        {
            temp=head;
            head=NULL;
            free(temp);
        }
    else
        {
            pre=head;
            curr=head->link;
             while(curr->link!=NULL)
             {
                 pre=curr;
                 curr=curr->link;
             }
             pre->link=NULL;
             free(curr);
        }
        display();
}

void deleteany(int key)
{
     struct node *pre,*curr,*temp;
     if(head==NULL)
             printf("list is empty. deletion not possible");
    else if(head->data==key)
        {
            temp=head;
            head=NULL;
            free(temp);
        }
    else
        {
            pre=head;
            curr=head;
             while(curr->data!=key&&curr->link!=NULL)
             {
                 pre=curr;
                 curr=curr->link;
             }
             if(curr->data!=key)
                 printf("search key not found insertion not possilble");
            else
                {
                    pre->link=curr->link;
                    free(curr);
                }
        }
        display();
}

void main()
{
    int opt,x,key;
    do
    {
        printf("\n enter the options \n1.insert front\n2.insert end\n3.insert after\n4.delete front\n5.delete end\n6.delete any\n7.display\n8.exit");
        scanf("%d",&opt);
        switch(opt)
            {
                case 1:printf("enter the new data");
                        scanf("%d",&x);
                        insertfront(x);
                        break;
                case 2: printf("enter the new data");
                        scanf("%d",&x);
                        insertend(x);
                        break; 
                case 3:printf("enter the search key");
                        scanf("%d",&key);
                        printf("enter the new data");
                        scanf("%d",&x);
                        insertafter(key,x);
                case 4:deletefront();break;
                case 5:deleteend();break;
                case 6:printf("enter the the node to be deleted");
                        scanf("%d",&key);
                        deleteany(key);
                        break;
                case 7:display();
                        break;
            }
    }while(opt!=8);
}