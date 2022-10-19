#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int count(node *head){
    int count=1;
    node *temp = head;
    do{
        temp=temp->next;
        count++;
    }while(temp!=head);
    return count;
}

void insert(node *head){
    node *newNode,*temp=head;
    int val,pos;
    printf("Enter value of the node:");
    scanf("%d",&val);
    printf("Enter position of the new node:");
    scanf("%d",&pos);
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=val;
    if(pos > count(head) || pos < 0){
        printf("Not Possible");
        return;
    }
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    temp->next=newNode->next;
    temp->next->prev=newNode;
    newNode->prev=temp;
}

void delete(node *head){
    int pos;
    printf("Enter location of node t0o be deleted:");
    scanf("%d",&pos);
    if(pos > count(head) || pos < 0){
        printf("Not Possible");
        return;
    }
    node *temp=head;
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
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

void search(node *head){
    int s;
    printf("Enter the Element to be searched: ");
    scanf("%d",&s);
    node *temp=head;
    do{
        if(temp->data==s){
            printf("Found");
            return;
        }
        temp=temp->next;
    }while(temp->next != head);
    printf("Not Found");
}

int main(){
   node *head=NULL;
   int n=1;
   printf("Enter your choice:\n1.Insert at position\n2.Delete from Position\n3.Traverse\n4.Search\n5.Exit\n");
   scanf("%d",&n);
   switch(n){
        case 1:
            insert(head);
            break;
        case 2:
            delete(head);
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            exit(0);
            break;
   } 
}