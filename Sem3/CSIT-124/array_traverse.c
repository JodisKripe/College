#include <stdio.h>

// Program to print an array
void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

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
    print(a, n);
}