// Quick Sort Program



#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5000


void quicksort(int[],int,int);
int partition(int[],int,int);

void main()
{
    int i,n,a[MAX],ch = 1;
    clock_t start,end;

    while(ch)
    {
        printf("\n Enter the number of elements: ");
        scanf("%d",&n);

        for(i=0;i<n;i++){
            a[i]= rand()%200;
        }

        printf("The random generated array is\n");
        for(i=0;i<n;i++){
            printf(" %d",a[i]);
        }

        start=clock();
        quicksort(a,0,n-1);
        end=clock();

        printf("\n\nThe sorted array elements are: ");
        for(i=0;i<n;i++){
            printf("%d, ",a[i]);
        }
        printf("\n");

        printf("Time taken = %f",(end-start)/CLK_TCK);

        printf("\n\nDo u wish to continue (0/1): ");
        scanf("%d",&ch);
    }
}


void quicksort(int a[],int low,int high)
{
    int mid;

    if(low < high)
    {
        mid=partition(a,low,high);
        quicksort(a,low,mid-1);
        quicksort(a,mid+1,high);
    }
}


int partition(int a[],int low,int high)
{
    int key,i,j,temp,k;
    key=a[low];
    i=low+1;
    j=high;

    while(i<=j)
    {
        while(i<=high && key>=a[i])
            i=i+1;
        while(key<a[j])
            j=j-1;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            k=a[j];
            a[j]=a[low];
            a[low]=k;
        }
    }
    return j;
}