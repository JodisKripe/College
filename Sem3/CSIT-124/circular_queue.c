#include <stdio.h>

// Program to implement circular queue using array

int main(){
    int n,front=-1,rear=-1,choice=1;
    printf("Enter size of queue:");
    scanf("%d",&n);
    int queue[n];
    while(choice){
        printf("Enter 1 to insert, 2 to delete, 3 to display:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                //printf("%d %d %d\n",rear,front,n);
                if((rear==front-1) || (front==0 && rear==n-1)){
                    printf("Queue is full");
                }
                else if(front==-1 && rear==-1){
                    front=rear=0;
                    printf("Enter data:");
                    scanf("%d",&queue[rear]);
                }
                else if (rear==n-1 && front!=0){
                    rear=0;
                    printf("Enter data:");
                    scanf("%d",&queue[rear]);
                }
                else{
                    printf("Enter element to insert:");
                    if(rear<n){scanf("%d",&queue[rear+1]);}
                    else{scanf("%d",&queue[0]);}
                    if(rear<n-1){rear=(rear+1);}
                    else{rear=0;}
                }
                break;
            case 2:
                if(front==rear){
                    printf("Queue is empty");
                    front=rear=-1;
                }
                else{
                    printf("Deleted element is %d",queue[front]);
                    if(front < n-1){front=(front+1);}
                    else{front=0;}
                }
                break;
            case 3:
                int i=front;
                //printf("%d , %d , %d\n\n",rear,front,queue[front]);
                if(rear!=n-1){
                    do{
                    printf("%d ",queue[i]);
                    if(i==n-1){i=0;}
                    else{i++;}
                
                }
                while(i!=rear+1);
                }
                else{
                    while(i!=rear){
                        printf("%d ",queue[i]);
                        i++;
                    }
                    printf("%d",queue[i]);
                }
                break;
            default:
                printf("Invalid choice");
        }
        printf("\n");
    }
    return 0;
}