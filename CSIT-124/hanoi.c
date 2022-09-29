#include <stdio.h>

//Program for Tower of Hanoi

int pop(int *stack[],int *top){
    *top--;
    return *stack[*top+1];
}

void towerOfHanoi(int disks,char source, char aux, char destination)
{
    if (disks == 1)
    {
        printf("\nMove 1 disk from rod %c to rod %c",source,destination);
    }
    else{
        towerOfHanoi(disks-1,source,destination,aux);
        printf("\nMove 1 disk from rod %c to rod %c", source,destination);
        towerOfHanoi(disks-1,aux,source,destination);
    }
}

int main(){
    char Source='A',aux='B',destination='C';
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    printf("\n");
    towerOfHanoi(n,Source,aux,destination);
    printf("\n");
    return 0;
}