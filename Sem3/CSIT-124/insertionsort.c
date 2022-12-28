#include <stdio.h>
void printArray(int array[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", array[i]);
}
printf("\n");
}
void insertionSort(int array[], int size) {
for (int step = 1; step < size; step++) {
int data = array[step];
int j = step - 1;
while (data < array[j] && j >= 0) {
array[j + 1] = array[j];
--j;
}
array[j + 1] = data;
}
}
int main() {
int data[5];
int x;
printf("\nEnter the number of elements: ");
scanf("%d",&x);
for(int i=0;i<x;i++)
{
printf("\nEnter element: ");
scanf("%d",&data[i]);
}
insertionSort(data, x);
printf("Sorted array in ascending order:\n");
printArray(data, x);
}

