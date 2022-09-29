#include <stdio.h>
#include <stdlib.h>
//Program to implement linked lists

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL,*temp,*newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
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
    temp=head;
    printf("Elements in linked list are:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}