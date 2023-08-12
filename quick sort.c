void swap(int arr[],int a,int b)
{
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int partition(int arr[],int l,int r) 
{
    int key=arr[l],i=l+1,j=r;
    do{
        while(arr[i]<key)
        i++;
        while(arr[j]>key ) 
        j--;
        if(i<j)
            swap(arr,i,j);
    }while(i<j);
    swap(arr,l,j);
    return j;
}

void Qsort(int arr[],int l,int r) 
{
    int pos;
    if(l<r) 
    {
    pos=partition(arr,l,r);
    Qsort(arr,l,pos-1);
    Qsort(arr,pos+1,r);
    }
}

void print(int a[],int n) 
{
    printf("The sorted array is :-");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void read(int a[],int n) 
{
    printf("enter the elements of array:- ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void main() 
{
    int a[100],n;
    printf("Enter size of array:- ");
    scanf("%d",&n);
    read(a,n);
    Qsort(a,0,n-1);
    print(a,n);
}