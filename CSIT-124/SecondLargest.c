// Code to find second largest element in an array

#include <stdio.h>

void main(){
    int array[] = {15,48,22,6,1,79,5,48,2,3156,4,8,1,561,2,19,84,5};
    int n = sizeof(array) / sizeof(array[0]);
    int i, j, max=array[0], sec=array[0];
    for (i = 0; i < n; i++)
    {
        if(array[i]>max){
            sec=max;
            max=array[i];
        }
        if(array[i]>sec && array[i] < max){
            sec=array[i];
        }
    }
    printf("Second largest element is %d\n%d", sec,max);
}