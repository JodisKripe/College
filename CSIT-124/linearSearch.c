#include <stdio.h>

int linear_search(int a[], int n, int ele)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

//Program to find the position of an element in an array

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
    printf("Enter the element to be searched: ");
    scanf("%d", &ele);
    pos = linear_search(a, n, ele);
    if (pos == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d\n", pos);
    }
}