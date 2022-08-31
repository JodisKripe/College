#include <stdio.h>

void insert(int a[], int n, int ele, int pos)
{
    int i;
    for (i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = ele;
}

//Program to insert an elemetn in an array

void main(){
    int n, ele, i,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n+1];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);
    printf("Enter Position of the new element: ");
    scanf("%d", &pos);
    insert(a, n, ele,pos);
    n++;
    printf("The array after insertion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}