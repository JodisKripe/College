#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void quicksort(int a[],int low,int high);
int partition(int a[],int low,int high);
void swap(int *a,int *b);
int main()
{
int a[MAX],n,i;
printf("Enter the number of elements in the array");
scanf("%d",&n);
printf("Enter the elements of the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(a,0,n-1);
printf("The sorted array is");
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
void quicksort(int a[],int low,int high)
{
int j;
if(low<high)
{
j=partition(a,low,high);
quicksort(a,low,j-1);
quicksort(a,j+1,high);
}
}
int partition(int a[],int low,int high)
{
int pivot,i,j;
pivot=a[low];
i=low+1;
j=high;
while(i<=j)
{
while(a[i]<=pivot && i<=high)
i++;
while(a[j]>pivot && j>=low)
j--;
if(i<j)
swap(&a[i],&a[j]);
}
swap(&a[low],&a[j]);
return j;
}
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}