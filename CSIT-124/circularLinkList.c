#include <stdio.h>
#include <stdlib.h>
//Program to implement Circular linked list

typedef struct node node;

struct node{
    int data;
    struct node *next;
};

int count(node *head){
    int count = 0;
    node *temp=head;
    if(head==NULL){
        return 0;
    }
    do{
        count++;
        temp=temp->next;
    }while(temp->next !=head);
    return count;
}

void insert(node *head, int data , int pos){
    node *temp;
    temp=head;
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    int i=1;
    
    if(head==NULL){
        printf("init");
        head=newnode;
        newnode->next=head;
    }
    else if(pos==1){
        node *temp=head;
        do{
            temp=temp->next;
        }while(temp->next!=head);
        newnode=head->next;
        head=newnode;
        temp->next=head;
    }
    else if(pos > count(head)){
        printf("Not possible");
        return;
    }
    else{
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
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
    temp=head;
    int counts= count(head);
    if(counts<pos){
        printf("Not possible");
        return;
    }
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    // temp points to node before the position
    newNode->next=temp->next;
    temp->next=newNode;
    head=c;
}


void delete(node *head, int pos){
    if(pos > count(head) || pos < 0){
        printf("Not Possible");
        return;
    }
    node *temp=head;
    int count=0;
    while(count < pos){
        count++;
        temp=temp->next;
    }
    temp->next = temp->next->next;
}

void traverse(node *head){
    node *temp=head;
    if(head==NULL){
        printf("Empty");
    }
    else
    {
        do{
        printf("%d ",temp->data);
        temp=temp->next;
        }while(temp->next != head);  
    }
}

int main(){
    int choice=1;
    struct node *head=NULL,*temp,*newnode;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode-> next = NULL;
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
            newnode->next=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to continue:");
        scanf("%d",&choice);
    }
    temp->next=head;
    /*node *newnode;
    node *newnode2;
    node *newnode3;
    node *newnode4;
    newnode = (node *)malloc(sizeof(node));
    newnode2 = (node *)malloc(sizeof(node));
    newnode3 = (node *)malloc(sizeof(node));
    newnode4 = (node *)malloc(sizeof(node));
    head=newnode;
    newnode->data=1;
    newnode->next=newnode2;
    newnode2->data=2;
    newnode2->next=newnode3;
    newnode3->data=3;
    newnode3->next=newnode4;
    newnode4->data=4;
    newnode4->next=head;
    node *temp=head;
    do{
    printf("%d",temp->data);
    temp=temp->next;
    }while(temp!=head);
    */
    while(1){
        printf("%d",count(head));
        printf("\n\n1. Insert at position\n2. Delete from position\n3. Traverse\n4. Exit\n$");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int posi,data;
                printf("\nEnter the data: ");
                scanf("%d",&data);
                printf("\nEnter the position: ");
                scanf("%d",&posi);
                insertion(head,data,posi);
                break;
            case 2:
                int posd;
                printf("Enter position: ");
                scanf("%d",&posd);
                delete(head,posd);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}

