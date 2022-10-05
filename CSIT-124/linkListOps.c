#include <stdio.h>
#include <stdlib.h>
//Program to implement linked lists operations like traversal, insertion and deletion

typedef struct node node;

struct node{
    int data;
    struct node *next;
};

void traversal(node *head){
    printf("\nElements of the linked list are:");
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
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
    while(temp!=NULL){
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
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count<pos){printf("Not possible");return;}
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    temp->next = temp->next->next;
}

int main(){
    struct node *head=NULL,*temp,*newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode-> next = NULL;
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue:");
        scanf("%d",&choice);
    }
    insertion(head,99,4);
    traversal(head);
    deletion(head,3);
    traversal(head);
    return 0;
}

