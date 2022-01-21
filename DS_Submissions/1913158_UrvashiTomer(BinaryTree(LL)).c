/********Binary Tree (with linked list)********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left, *right;
};

struct node * create()
{
	int choice;
	struct node *nn;
	nn = (struct node *)malloc(sizeof(nn));
	printf("Enter data : ");
	scanf("%d",&nn->data);
	nn->left=NULL;
	nn->right=NULL;
	printf("\nIf %d has a left node, Press 1 else 0 : ",nn->data);
	scanf("%d",&choice);
	if(choice)
	{
		nn->left=create();
	}
	printf("\nIf %d has a right node, Press 1 else 0 : ",nn->data);
	scanf("%d",&choice);
	if(choice)
	{
		nn->right=create();
	}
	return nn;
}

void in_order(struct node * root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		in_order(root->left);
		printf("%d ",root->data);
		in_order(root->right);
	}
}

void pre_order(struct node * root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void post_order(struct node * root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		post_order(root->left);
		post_order(root->right);
		printf("%d ",root->data);
	}
}

int main()
{
	struct node *root;
	root == NULL;
	root = create();
	printf("\nBinary tree implemented successfully!");
	printf("\nThe Inorder traversal is : ");
	in_order(root);
	printf("\nThe Preorder traversal is : ");
	pre_order(root);
	printf("\nThe Postorder traversal is : ");
	post_order(root);
	return 0;
}
