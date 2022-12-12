#include <stdio.h>
#include <stdlib.h>

typedef struct bintree node;

struct bintree{
    int data;
    struct bintree* left;
    struct bintree* right;
};

void insert(int a,node* root){
    //printf("%d",root->data);
    if(root==NULL){
        root=(node *)malloc(sizeof(node));
        root->data=a;root->left=NULL;root->right=NULL;
        printf("init%d\n",root->data);
        return;
    }
    if(a > root -> data){
        if(root->right==NULL){
            node *newNode;
            newNode = (node *)malloc(sizeof(node));
            newNode->data=a;
            newNode->left=NULL;
            newNode->right=NULL;
            root->right=newNode;
            //printf("right");
            return;
        }
        insert(a,root->right);
    }
    else if(a< root->data){
        if(root->left==NULL){
            node *newNode;
            newNode = (node *)malloc(sizeof(node));
            newNode->data=a;
            newNode->left=NULL;
            newNode->right=NULL;
            root->left=newNode;
            //printf("left");
            return;
        }
        insert(a,root->left);
    }
}

void inorder(node *root){
    if(root ==NULL){
        return;
    }
    if(root -> left !=NULL){
        inorder(root->left);
    }
    printf("%d ",root->data);
    if(root -> right != NULL){
        inorder(root->right);
    }
}

int main()
{
    node* root=NULL;
    root=(node*)malloc(sizeof(node));
    root->data=0;root->left=NULL;root->right=NULL;
    insert(4,root);
    //printf("%d",root->data);
    insert(3,root);
    insert(12,root);
    insert(52,root);
    insert(7,root);
    insert(5,root);
    insert(99,root);
    insert(88,root);
    insert(1,root);
    insert(6,root);
    insert(17,root);
    inorder(root);
    return 0;
}
