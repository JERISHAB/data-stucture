#include <stdio.h>

void insertionsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
		{temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
			{
				a[j+1]=a[j];
				j--;
			}
		a[j+1]=temp;
		}
}


void main()
{
	int a[50],n,i;
	
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array ");
	for(i=0;i<n;i++)	
		scanf("%d",&a[i]);
		
	insertionsort(a,n);
	 printf("the sorted array is");	
	 	for(i=0;i<n;i++)	
			{
			printf("%d",a[i]);
			printf("\n");
			}
}			
