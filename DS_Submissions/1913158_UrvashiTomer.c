/* LINEAR QUEUE*/

#include<stdio.h>
#include<stdlib.h>
#define max 20

int isfull(int *rear);
int isempty(int *front, int *rear);
int enqueue ( int queue[max], int *rear , int *val);
int dequeue( int queue[max], int *front, int *rear);
void peek(int queue[max], int *front, int *rear);
void display(int queue[max], int *front, int *rear);

int main()
{
	int queue[max],val;
	int front,rear,choice;
	
	front = 0;
	rear = -1;
	printf("\n 1. Insert element in queue");
	printf("\n\n 2. Delete element from queue");
	printf("\n\n 3. Element at front location");
	printf("\n\n 4. Display the elements of queue");
	printf("\n\n 5. Exit");
	while(1)
	{
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("\nEnter Number : ");
				scanf("%d",&val);
				enqueue(queue,&rear,&val);
				break;
			case 2 : 
				dequeue(queue,&front,&rear);
				break;
			case 3:
				peek(queue, &front, &rear);
				break;
			case 4:
				display(queue, &front, &rear);
				break;
			case 5:
				exit(0);
		}
	}
	return(0);
}

int enqueue ( int queue[max], int *rear , int *val)
{
	if(isfull(rear))
	{
		printf("\nQueue is full");
	}
	    
	else
	{
	    *rear = *rear + 1;
	    queue[*rear] = *val;
	    return *val;
	}
}

int dequeue( int queue[max], int *front, int *rear)
{
	int val;
	if (isempty(front, rear))
	{
		printf("\nQueue is empty");
	}
   
	else
	{
		val = queue[*front];
	    (*front)++;
	    printf("\nDeleted number is : %d\n", val);
	    return val;
	}
}

int isempty(int *front, int *rear)
{
	if(*front > *rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull(int *rear)
{
	if(*rear==max-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void peek(int queue[max], int *front,int *rear)
{
	if (isempty(front, rear))
	{
		printf("\nQueue is empty");
	}
	  
	else
	{
		printf("\nThe element at Front Position is : %d",queue[*front] );
	}
}

void display(int queue[max], int *front, int *rear)
{
	int i;
	if (isempty(front, rear))
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nThe elements are :");
		for(i=*front; i<=*rear; i++)
		{
			printf("%d ,",queue[i]);	
		}	
	}	

}

