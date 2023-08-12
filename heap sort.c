#include<stdio.h>

void heapify(int i, int s, int a[]) 
{
  int lc = 2 * i;
  int rc = (2 * i) + 1;
  int lar = i;
  if (lc <= s && a[lc] > a[lar])
    lar = lc;
  if (rc <= s && a[rc] > a[lar])
    lar = rc;
  if (lar != i) 
  {
    int tmp = a[i];
    a[i] = a[lar];
    a[lar] = tmp;
    heapify(lar, s, a);
  }
}

void Buildheap(int a[], int s) 
{
  for (int i = s / 2; i >= 1; i--)
    heapify(i, s, a);
}

void Heapsort(int a[], int s) 
{
  Buildheap(a, s);
  for (int i = s; i > 1; i--) 
  {
    int tmp = a[i];
    a[i] = a[1];
    a[1] = tmp;
    heapify(1, i - 1, a);
  }
}

void main() 
{
  int a[100], s, i;
  printf("Enter the size:");
  scanf("%d", & s);
  printf("Enter the elements:");
  for (i = 1; i <= s; i++)
        scanf("%d", & a[i]);
  Heapsort(a, s);
  printf("The Sorted array :");
  for (i = 1; i <= s; i++) 
  {
    printf("%d\t", a[i]);
  }
}