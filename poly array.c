#include <stdio.h>
int p[100];
void polyeval(int q[],int n)
{
    printf("Enter the coefficients : ");
    for(int i=n;i>=0;i--)
        scanf("%d",&q[i]);
}

void addpoly(int p1[],int n1,int p2[],int n2)
{
    int i=0,j=0,k=0;
    while(i<=n1&&j<=n2)
    {
        p[k]=p1[i]+p2[j];
        k++,i++,j++;
    }
    while(i<=n1)
    {
        p[k]=p1[i];
        i++,k++;
    }
    while(j<=n2)
    {
        p[k]=p2[j];
        k++,j++;
    }
}

void display(int a[],int n)
{
 for(int i=n;i>=0;i--)   
    {
        printf("%dX^%d",a[i],i);
        if(i!=0)
            printf(" + ");
    }
}

int max(int n1,int n2)
{
    if(n1>n2)
        return n1;
    return n2;    
}

void main()
{
    int n1,n2,p1[100],p2[100];
    printf("Enter the degree of the first polynomial : ");
    scanf("%d",&n1);
    polyeval(p1,n1);
    printf("the first polynomial : ");
    display(p1,n1);
    printf("\nEnter the degree of second polynomial : ");
    scanf("%d",&n2);
    polyeval(p2,n2);
    printf("The second polynomial : ");
    display(p2,n2);
    addpoly(p1,n1,p2,n2);
    printf("\nThe resultant polynomial is : ");
    display(p,max(n1,n2));
}
