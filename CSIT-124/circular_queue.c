#include <stdio.h>

// Program to implement circular queue using array

int main(){
    int queue[3],n,front=0,rear=0,choice=1;
    printf("Enter size of queue:");
    scanf("%d",&n);
    while(choice){
        printf("Enter 1 to insert, 2 to delete, 3 to display:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if((rear+1)%n==front){
                    printf("Queue is full");
                }
                else{
                    printf("Enter element to insert:");
                    scanf("%d",&queue[rear]);
                    rear=(rear+1)%n;
                }
                break;
            case 2:
                if(front==rear){
                    printf("Queue is empty");
                }
                else{
                    printf("Deleted element is %d",queue[front]);
                    front=(front+1)%n;
                }
                break;
            case 3:
                if(front==rear){
                    printf("Queue is empty");
                }
                else{
                    printf("Elements in queue are:");
                    for(int i=front;i!=rear;i=(i+1)%n){
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