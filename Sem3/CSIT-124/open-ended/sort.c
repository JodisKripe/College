To perform Insertion Sort

#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[10],i,j,n,temp;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=1;i<n;i++)
{
temp=a[i];
j=i-1;
while((temp<a[j])&&(j>=0))
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;
}
printf("The sorted array is: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}

To perform Selection Sort

#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[10],i,j,n,temp,min;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[min])
min=j;
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
printf("The sorted array is: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}

To perform Heap Sort

#include<stdio.h>
#include<stdlib.h>
void heapify(int a[],int n,int i)
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
if((l<n)&&(a[l]>a[largest]))
largest=l;
if((r<n)&&(a[r]>a[largest]))
largest=r;
if(largest!=i)
{
int temp=a[i];
a[i]=a[largest];
a[largest]=temp;
heapify(a,n,largest);
}
}
void heapsort(int a[],int n)
{
int i;
for(i=n/2-1;i>=0;i--)
heapify(a,n,i);
for(i=n-1;i>=0;i--)
{
int temp=a[0];
a[0]=a[i];
a[i]=temp;
heapify(a,i,0);
}
}
void main()
{
int a[10],i,n;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
heapsort(a,n);
printf("The sorted array is: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}

To perform Merge Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
int main()
{
int a[MAX],n,i;
printf("Enter the number of elements in the array");
scanf("%d",&n);
printf("Enter the elements of the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
mergesort(a,0,n-1);
printf("The sorted array is");
for(i=0;i<n;i++)
printf("%d",a[i]);
return 0;
}
void mergesort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void merge(int a[],int low,int mid,int high)
{
int i,j,k,c[MAX];
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
{
c[k]=a[i];
i++;
k++;
}
while(j<=high)
{
c[k]=a[j];
j++;
k++;
}
for(k=low;k<=high;k++)
a[k]=c[k];
}

To perform Quick Sort

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
printf("%d",a[i]);
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

To perform Shell Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void shellsort(int a[],int n);
int main()
{
int a[MAX],n,i;
printf("Enter the number of elements in the array");
scanf("%d",&n);
printf("Enter the elements of the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
shellsort(a,n);
printf("The sorted array is");
for(i=0;i<n;i++)
printf("%d",a[i]);
return 0;
}
void shellsort(int a[],int n)
{
int i,j,k,temp;
for(i=n/2;i>0;i=i/2)
{
for(j=i;j<n;j++)
{
for(k=j-i;k>=0;k=k-i)
{
if(a[k+i]>=a[k])
break;
else
{
temp=a[k];
a[k]=a[k+i];
a[k+i]=temp;
}
}
}
}
}