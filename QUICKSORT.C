#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
int partition(int a[size],int l,int r)
{
    int i,j,pivot,temp;
    pivot=a[l];
    i=l+1;
    j=r;
    while(1)
    {

        while(pivot>=a[i] && i<=r)
        {
            count++;
            i++;
        }
        while(pivot<a[j])
        {
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[j];
            a[j]=a[l];
            a[l]=temp;
            return j;

        }
    }
}
void quicksort(int a[size],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}

int main()
{
    int i,n,a[size];
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("\nEnter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Sorted elements are:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("Number of comparisons is %d",count);
}
