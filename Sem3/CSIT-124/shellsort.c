#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


void shellsort(int a[],int n);

int main(){
    int a[MAX],n,i;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    shellsort(a,n);
    printf("The sorted array is");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
    
void shellsort(int a[],int n){
    int i,j,k,temp;
    for(i=n/2;i>0;i=i/2){
        for(j=i;j<n;j++){
            for(k=j-i;k>=0;k=k-i){
                if(a[k+i]>=a[k])
                break;
                else{
                    temp=a[k];
                    a[k]=a[k+i];
                    a[k+i]=temp;
                }
            }
        }
    }
}