#include <stdio.h>
int binarySearch(int a[],int l,int r,int x)
{
    if (l<r)
      {
        int m = (l+r)/2;
        if(x==a[m])
            return m;
        else if(x<a[m])
            return binarySearch(a,l,m-1,x);
        else
            return binarySearch(a,m+1,r,x);
      }
      return -1;
}

void main()
{
    int a[50],n,x;
    printf("Enter the limit");
    scanf("%d",&n);
    printf("enter the numbers");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to be searched");
    scanf("%d",&x);
    int result = binarySearch(a,0,n,x) ;
    if (result==-1)
        printf("not found");
    else
        printf("number found at %d",result+1);
    
}