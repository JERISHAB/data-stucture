#include <stdio.h>
int linearSearch(int A[],int n,int x)
{
    for(int i=0;i<n;i++)
            if(A[i]==x)
                return i;
    return -1;            
}

void main()
{
    int a[50],x,i,n;
    printf("Enter the limit ");
    scanf("%d",&n);
    printf("Enter the numbers");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to found"); 
    scanf("%d",&x);
    int result = linearSearch(a,n,x)  ;  
    if(result==-1)
        printf("element not found");
    else
        printf("element found at positon %d",result+1);
}