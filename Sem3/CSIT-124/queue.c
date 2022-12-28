#include <stdio.h>

// Program to implement queue using array

int main(){
    int queue[100],n,front=0,rear=0,choice=1;
    printf("Enter size of queue:");
    scanf("%d",&n);
    while(choice){
        printf("Enter 1 to insert, 2 to delete, 3 to display:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(rear==n){
                    printf("Queue is full");
                }
                else{
                    printf("Enter element to insert:");
                    scanf("%d",&queue[rear]);
                    rear++;
                }
                break;
            case 2:
                if(front==rear){
                    printf("Queue is empty");
                }
                else{
                    printf("Deleted element is %d",queue[front]);
                    front++;
                }
                break;
            case 3:
                if(front==rear){
                    printf("Queue is empty");
                }
                else{
                    printf("Elements in queue are:");
                    for(int i=front;i<rear;i++){
                        printf("%d ",queue[i]);
                    }
                }
                break;
            default:
                printf("Invalid choice");
        }
        printf("\n");
    }
    return 0;
}