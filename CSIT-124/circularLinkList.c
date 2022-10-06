#include <stdio.h>
#include <stdlib.h>
//Program to implement Circular linked list

typedef struct node node;

struct node{
    int data;
    struct node *next;
};

void traversal(node *head){
    printf("\nElements of the linked list are:");
    node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

void insertion(node *head, int value , int pos){
    //printf("init");
    node *c=head;
    node *newNode,*temp;
    newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        printf("init");
        head = newNode;
        return;
    }
    int count=1;
    temp=head;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    if(count<pos){printf("Not possible");return;}
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    // temp points to node before the position
    newNode->next=temp->next;
    temp->next=newNode;
    head=c;
}

void deletion(node *head , int pos){
    if(head==NULL){
        printf("Underflow");
        return;
    }
    node *temp=head;
    int count=1;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    if(count<pos){printf("Not possible");return;}
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    // temp points to node before the position
    node *temp2=temp->next;
    temp->next=temp2->next;
}

int main(){
    node *head=NULL;
    int choice,value,pos;
    while(1){
        printf("\n1. Insertion \n2. Deletion \n3. Traversal \n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value and position:");
                scanf("%d %d",&value,&pos);
                insertion(head,value,pos);
                break;
            case 2:
                printf("Enter position:");
                scanf("%d",&pos);
                deletion(head,pos);
                break;
            case 3:
                traversal(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice");
        }
    }
}