#include <stdio.h>

// Program to implement stack using array

int main(){
    int choice, n=100, top=-1, x;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    int stack[n];
    while(choice!=4){
    printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice:");
    scanf("%d",&choice);
    printf("\n");
    switch(choice){
        case 1:
            if(top==n-1){
                printf("Stack Overflow");
                break;
            }
            int temp;
            printf("Enter Element:");
            scanf("%d",&temp);
            top++;
            stack[top]=temp;
            break;
        case 2:
            if(top != -1){top--;}
            else{printf("Stack Underflow");}
            break;
        case 3:
            if(top==-1){
                printf("There are no elements in the stack");
                break;
            }
            for(int i=0;i<=top;i++){
                printf("%d\n",stack[i]);
            }
            break;
        case 4:
            break;
        default:
            break;
    }
    }
    printf("EXIT");
}