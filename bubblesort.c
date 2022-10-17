#include <stdio.h>



void swap(int a[],int g,int h)
	{
		int temp;
		temp=a[g];
		a[g]=a[h];
		a[h]=temp;
	}
		
void bubblesort(int a[],int n)
{
	int pass,j;
	for(pass=1;pass<n;pass++)
		for(j=0;j<n-pass;j++)
			{
				if(a[j]>a[j+1])
					swap(a,j,j+1);
			}
}	

void main()
{
	int n,i,a[50];
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("the entered array is");
	for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			printf("\n");
		}			
	bubblesort(a,n);
	
	printf("the sorted array is");
	for(i=0;i<n;i++)
		{
		printf("%d",a[i]);	
		printf("\n");
		}
}				
		
