#include <stdio.h>

void delete(int a[], int n, int ele)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (a[i] == ele)
            {
                for (; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }
                a[i] = 0;
            }
        }
    }

// Program to delete an element from an array

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
    printf("Enter the element to be deleted: ");
    scanf("%d", &ele);
    delete(a, n, ele);
    n--;
    printf("The array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}