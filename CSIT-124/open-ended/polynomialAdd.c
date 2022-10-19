#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int coeff;
    int exp;
    struct node *next;
};

void makePol(node *head){
    node *temp=head;
    node *newNode;
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    int choice=1,coeff,exp;
    while(choice){
        printf("Enter the coefficient:");
        scanf("%d",&coeff);
        printf("Enter the exponent:");
        scanf("%d",&exp);
        if(head==NULL){
            newNode->coeff=coeff;
            newNode->exp=exp;
            head=temp=newNode;
            return;
        }
        do{
            if(temp->exp==exp){
                temp->coeff+=coeff;
                return;
            }
            temp=temp->next;
        }while(temp->next->exp>=exp);
        newNode->coeff=coeff;
        newNode->exp=exp;
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Do you want to continue?(1/0)");
        scanf("%d,&choice");
    }
}

node* add(node *p1, node *p2){
    node *temp1=p1,*temp2=p2;
    node *newNode;
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            newNode->coeff=temp1->coeff+temp2->coeff;
            newNode->exp=temp1->exp;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp){
            newNode->coeff=temp1->coeff;
            newNode->exp=temp1->exp;
            temp1=temp1->next;
        }
        else{
            newNode->coeff=temp2->coeff;
            newNode->exp=temp2->exp;
            temp2=temp2->next;
        }
        newNode=newNode->next;
    }
    while(temp1!=NULL){
        newNode->coeff=temp1->coeff;
        newNode->exp=temp1->exp;
        temp1=temp1->next;
        newNode=newNode->next;
    }
    while(temp2!=NULL){
        newNode->coeff=temp2->coeff;
        newNode->exp=temp2->exp;
        temp2=temp2->next;
        newNode=newNode->next;
    }
    return newNode;
}

int traverse(node *head){
    node *temp=head;
    int count=0;
    do{
        printf("%dx^%d",temp->coeff,temp->exp);
        temp=temp->next;
        count++;
    }while(temp!=NULL);
    return count;
}

int main(){
    node *p1=NULL,*p2=NULL,*p3=NULL;
    printf("Enter the first polynomial:");
    makePol(p1);
    traverse(p1);
    makePol(p2);
    p3=add(p1,p2);
    traverse(p3);
    return 0;
}