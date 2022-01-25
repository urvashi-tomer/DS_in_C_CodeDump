/***********Linked list implementation**********/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *nn ,*head=NULL,*traverse;
	int choice;
	printf("Do you want to create a linked list? \n1. Yes \n2. No");
	scanf("%d",&choice);
	
	while(choice==1)
	{
		nn = (struct node *) malloc(sizeof(struct node));
		printf("\nEnter the data in the new node : ");
		scanf("%d",&nn->data);
		nn->next = NULL;
		
		if(head==NULL)
		{
			head=nn;
			traverse=nn;
		}
		else
		{
			traverse->next=nn;	
			traverse=nn; 		
		}
			
		printf("\nDo you want to add more elements? \n1. Yes \n2. No");
		scanf("%d",&choice);	
	}	
	
	traverse = head;
	while(traverse!=NULL)	
	{
		printf("\nThe data is : %d",traverse->data);
		traverse = traverse->next;
	}

	return 0;
}
