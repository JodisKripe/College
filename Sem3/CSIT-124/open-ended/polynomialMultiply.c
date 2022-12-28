#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;

struct node{
    int coeff;
    int exp;
    struct node *next;
};

node* makePol(node *head){
    node *temp=head;
    int choice=1;
    printf("Enter the coefficient and exponent of the polynomial in decreasing order of exponent"); 
    while(choice){
        node *newNode;
        newNode=(node *)malloc(sizeof(node));
        newNode->coeff=0;
        newNode->exp=0;
        newNode->next=NULL;
        printf("\n\nEnter the coefficient: ");
        scanf("%d",&newNode->coeff);
        printf("Enter the exponent: ");
        scanf("%d",&newNode->exp);
        if(temp==NULL){
            printf("init");
            head=newNode;
            temp=head;
            continue;
        }
        temp->next=newNode;
        temp=temp->next;
        printf("Do you want to continue? (1/0): ");
        scanf("%d",&choice);
    }
    printf("Polynomial created\n");
    /*node *temp2=head;
    do{
        printf("%dx^%d +",temp2->coeff,temp2->exp);
        temp2=temp2->next;
    }while(temp2!=NULL);
    */
    return head;
    
}
    
node* multiply(node* P1, node* P2){
    node* p1=P1;
    node* p2=P2;
    node* p3=NULL;
    node* temp=p3;
    node* temp2=p3;
    while(p1!=NULL){
        while(p2!=NULL){
            node* newNode;
            newNode=(node *)malloc(sizeof(node));
            newNode->coeff=0;
            newNode->exp=0;
            newNode->next=NULL;
            newNode->coeff=p1->coeff*p2->coeff;
            newNode->exp=p1->exp+p2->exp;
            if(p3==NULL){
                p3=newNode;
                temp=p3;
                continue;
            }
            while(temp2!=NULL){
                if(temp2->exp==newNode->exp){
                    temp2->coeff+=newNode->coeff;
                    break;
                }
                temp2=temp2->next;
            }
            temp->next=newNode;
            temp=temp->next;
            p2=p2->next;
        }
        p1=p1->next;
        p2=P2;
    }
    return p3;
}

void traverse(node *head){
    printf("\n");
    node *temp=head;
    do{
        printf("%dx^%d +",temp->coeff,temp->exp);
        temp=temp->next;
    }while(temp!=NULL);
    return;
}

int main(){
    node *p1=NULL,*p2=NULL,*p3=NULL;
    printf("Enter the first polynomial:");
    p1=makePol(p1);
    traverse(p1);
    p2=makePol(p2);
    traverse(p2);
    p3=multiply(p1,p2);
    traverse(p3);
    return 0;
}