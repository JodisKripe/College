#include <stdio.h>

// Code to do binary search in an array
int binary_search(int a[], int n, int ele)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2; 
        if (a[mid] == ele)
        {
            return mid;
        }
        else if (a[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    int n = sizeof(array) / sizeof(array[0]);
    int ele;
    printf("Enter the element to be searched: ");
    scanf("%d", &ele);
    int pos = binary_search(array, n, ele);
    if (pos != -1)
    {
        printf("Element found at position %d\n", pos);
    }
    else
    {
        printf("Element not found\n");
    }
}