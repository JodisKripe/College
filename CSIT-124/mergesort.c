#include<stdio.h>
void merge(int arr[], int p, int q, int r)
{
int n1 = q - p + 1;
int n2 = r - q;
int L[n1], M[n2];
for (int i = 0; i < n1; i++)
L[i] = arr[p + i];
for (int j = 0; j < n2; j++)
M[j] = arr[q + 1 + j];
int i, j, k;
i = 0;
j = 0;
k = p;
while (i < n1 && j < n2) {
if (L[i] <= M[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = M[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = M[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r) {
if (l < r)
{
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
void print(int arr[], int size)
{
for(int i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
}
int main()
{
int data[5];
int size;
printf("Enter the number of elements: ");
scanf("%d",&size);
for(int i=0;i<size;i++)
{
printf("Enter element A[%d]: ",i);
scanf("%d",&data[i]);
}
printf("\nElements before sorting are: ");
print(data,size);
mergeSort(data,0,size-1);
printf("\nElements after sorting are: ");
print(data,size);
return 0;
}