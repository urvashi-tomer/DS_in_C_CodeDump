#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

int isfull(int rear);
int isempty(int front, int rear);
int dequeue( int queue[SIZE], int *front, int *rear);
int enqueue ( int queue[SIZE],int *front, int *rear , int val);

int main()
{
	int execute[100], calling[100], front, rear,frontEX,rearEX, time, process,i, val, insert;
	front=-1;
	rear=-1;
	frontEX=-1;
	rearEX=-1;
	time=0;
	printf("\nEnter number of processes(1 - 100) : ");
	scanf("%d",&process);
	if(1<=process && process<=100)
	{
		printf("\n Enter calling order : ");
		for(i=0; i<process; i++)
		{
			scanf("%d", &insert);
			enqueue(calling,&front, &rear, insert);
			
		}
		printf("\n Enter execution order : ");
		for(i=0; i<process; i++)
		{
			scanf("%d", &insert);
			enqueue(execute ,&frontEX, &rearEX, insert);
			
		}
		while(frontEX != process)
		{
			if(execute[frontEX] != calling[front])
			{
				val = dequeue(calling, &front, &rear);
				enqueue(calling,&front, &rear, val);
				time++;
			}
			else 
			{
				val=dequeue(calling, &front, &rear);
				val=dequeue(execute, &frontEX, &rearEX);
				//printf("\nExecuted Successfully");
				time++;
			}
		}
		printf("\nTime taken : %d",time);
	}
	else
	{
		printf("\nInvalid choice...");
	}

	return 0;
}

int enqueue ( int queue[SIZE],int *front, int *rear , int val)
{
	if(isfull(*rear))
	{
		printf("\nQueue is full");
	}
	else if(*front == -1 && *rear==-1)
	{
		*front = *front + 1;
		*rear = *rear + 1;
	    queue[*rear] = val;
	}
	    
	else
	{
	    *rear = *rear + 1;
	    queue[*rear] = val;   
	}
	return val;
}

int dequeue( int queue[SIZE], int *front, int *rear)
{
	int val;
	if (isempty(*front, *rear))
	{
		printf("\nQueue is empty");
	}
   
	else
	{
		val = queue[*front];
	    (*front)++;
	    return val;
	}
}

int isempty(int front, int rear)
{
	if(front == -1 && rear==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull(int rear)
{
	if(rear==SIZE-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

