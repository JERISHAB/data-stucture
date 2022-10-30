
#include <stdio.h>
void swap(int *A,int i,int k)
{
    int temp;
    temp=A[k];
    A[k]=A[i];
    A[i]=temp;
}



void selectionsort(int A[],int n )
{
    int i;
    for(i=0;i<n;i++)
        {
            int k=i,j;
            
            for(j=i+1;j<n;j++)
                   { if(A[j]<A[k])
                        k=j;
                   }    
            swap(A,i,k);            
        }
}

int main()
{
    int n,a[50],i;
    printf("enter the size of the array");
    scanf("%d",&n);
    printf("enter the array");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    selectionsort(a,n);   
    printf("the sorted array is"); 
     for(i=0;i<n;i++)
            printf("%d",a[i]);



}
