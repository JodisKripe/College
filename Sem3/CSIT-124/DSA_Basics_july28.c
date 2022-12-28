#include <stdio.h>

//Program to insert an element in an array

void insert(int a[], int n, int ele, int pos)
{
    int i;
    for (i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = ele;
}

//Program to delete an element from an array

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

void main()
{
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
    printf("The array after insertion: ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter the element to be deleted: ");
    scanf("%d", &ele);
    delete(a, n + 1, ele);
    printf("The array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    print(a, n);
}