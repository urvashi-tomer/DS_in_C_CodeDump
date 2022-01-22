/***********Binary Tree(array)**********/
#include<stdio.h>
#include<conio.h>
#include<math.h>

int root(char tree[], char root_node, int i);
int left_node(char tree[], char leftnode, int i);
int right_node(char tree[], char rightnode, int i);
void display_tree(char tree[], int max_nodes);

int main()
{
	char tree[100], rootnode, left_ch, right_ch;
	int index, choice, height ,max_nodes, i;
	
	printf("\nEnter height of the binary tree : ");
	scanf("%d",&height);
	
	max_nodes = pow(2,height)-1;
	
	printf("\nEnter root node : ");
	scanf(" %c",&rootnode);
	
	root(tree, rootnode ,0);
	
	for(i=0; i<max_nodes/2 ; i++)
	{	
		if(tree[i]=='$')
		{
			left_node(tree,'$',i);
			right_node(tree,'$',i);
		}
		else
		{
			printf("\nIf node %c has left child, Press 1 : ", tree[i]);
			scanf("%d",&choice);
			if(choice==1)
			{
				printf("\nEnter left child : ");
				scanf(" %c",&left_ch);
				left_node(tree,left_ch,i);
			}
			else
			{
				left_node(tree,'$',i);
			}
			printf("\nIf node %c has right child, Press 1 : ", tree[i]);
			scanf("%d",&choice);
			if(choice==1)
			{
				printf("\nEnter right child : ");
				scanf(" %c",&right_ch);
				right_node(tree,right_ch,i);
			}
			else
			{
				right_node(tree,'$',i);
			}
		}
	}
	
	display_tree(tree,max_nodes);
	return 0;
}

int root(char tree[], char root_node, int i)
{
	tree[i] = root_node;
	return 0;
}
int left_node(char tree[], char leftnode, int i)
{ 
	tree[(i * 2)+1] = leftnode;	
	return 0;
}
int right_node(char tree[], char rightnode, int i)
{
	tree[(i * 2) + 2] = rightnode;
	return 0;
}
void display_tree(char tree[], int max_nodes)
{
	int i=0;
	printf("\nThe tree is : ");
	while(i<max_nodes)
	{
		printf("%c ",tree[i]);
		i++;
	}
}
