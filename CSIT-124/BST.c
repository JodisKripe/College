#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree=NULL;
struct node* insertelement(struct node *tree,int n)
{
    struct node *newnode,*nodeptr,*parentptr;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    if(tree==NULL)
    {
        tree=newnode;
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(n<nodeptr->data)
                nodeptr=nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if(n<parentptr->data)
            parentptr->left=newnode;
        else
            parentptr->right=newnode;
    }
    return tree;
};
struct node *minValueNode(struct node *node) 
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL) 
        return tree;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else 
    {
        if (root->left == NULL) 
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int inorder(struct node *tree)
{
    while(tree!=NULL)
    {
        inorder(tree->left);
        printf("\t%d",tree->data);
        inorder(tree->right);
        return 0;
    }
}
int postorder(struct node *tree)
{
    while(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("\t%d",tree->data);
        return 0;
    }
}
int preorder(struct node *tree)
{
    while(tree!=NULL)
    {
        printf("\t%d",tree->data);
        preorder(tree->left);
        preorder(tree->right);
        return 0;
    }
}
int main()
{
    struct node* root = insertelement(root,8);
    insertelement(root, 18);
    insertelement(root, 24);
    insertelement(root, 11);
    insertelement(root, 12);
    printf("The Inorder Traversal is:\n");
    inorder(root); 
    deleteNode(root,12);
    printf("\nThe Inorder Traversal is:\n");
    inorder(root);
    
    printf("\n Preorder Traversal is:\n");
    preorder(root);
    printf("\n Postorder Traversal is:\n");
    postorder(root);
}