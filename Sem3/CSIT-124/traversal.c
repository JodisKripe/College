#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
};
void inorder_traversal(struct node* root)
{
if(root==NULL)
{
return;
}
else
{
inorder_traversal(root->left);
printf("%d -> ",root->data);
inorder_traversal(root->right);
}
}
void preorder_traversal(struct node* root)
{
if(root==NULL)
{
return;
}
else
{
printf("%d -> ",root->data);
preorder_traversal(root->left);
preorder_traversal(root->right);
}
}
void postorder_traversal(struct node* root)
{
if(root==NULL)
{
return;
}
else
{
postorder_traversal(root->left);
postorder_traversal(root->right);
printf("%d -> ",root->data);
}
}
struct node* createnode(int val)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
}
int main()
{
int x;
int i=0;
int j=0;
int k=0;
int val;
struct node* root;
while(1)
{
printf("\nPress 1. To insert data in root.\nPress 2. To insert in left node\nPress 3. To \
insert in right node\nPress 4. For inorder traversal\nPress 5. For preorder traversal\nPress \
6. For postorder traversal\nPress 7. To exit\n");
scanf("%d",&x);
switch(x)
{
case 1:
{
printf("Enter the value to be inserted: ");
scanf("%d",&val);
root=createnode(val);
if(k!=0)
{
printf("Root node is already created :-( ");
exit(0);
}
k++;
break;
}
case 2:
{
printf("Enter the value to be inserted: ");
scanf("%d",&val);
root->left=createnode(val);
i++;
if(i=!0)
{
if(root==NULL)
{
root->left->left=createnode(val);
}
}
break;
}
case 3:
{
printf("Enter the value to be inserted: ");
scanf("%d",&val);
root->right=createnode(val);
j++;
if(j=!0)
{
if(root==NULL)
{
root->right->right=createnode(val);
}
}
break;
}
case 4:
{
printf("Inorder traversal \n");
inorder_traversal(root);
break;
}
case 5:
{
printf("\nPreorder traversal \n");
preorder_traversal(root);
break;
}
case 6:
{
printf("\nPostorder traversal \n");
postorder_traversal(root);
break;
}
case 7:
{
exit(0);
}
default:printf("\nWrong Choice entered: !-!");
}
}
return 0;
}