/******** Implementation of Priority Queue *******/

#include<stdio.h>
#define N 20
int Queue[N],Pri[N];
int rear = -1,front = -1;

void enqueue(int data,int p)
{
	int i;
	if((front==0)&&(rear==N-1)) 
	{
		printf("\nQueue is full!");
	}	
	else
	{
		if(front==-1)
		{
			front = rear = 0;
			Queue[rear] = data;
			Pri[rear] = p;
		}
		else if(rear == N-1)
		{
			for(i=front;i<=rear;i++) 
			{
				Queue[i-front] = Queue[i]; 
				Pri[i-front] = Pri[i]; 
				rear = rear-front; 
				front = 0; 
			    for(i = rear;i>front;i--)
				{
					if(p<Pri[i])
					{
						Queue[i+1] = Queue[i];
						Pri[i+1] = Pri[i];
					}
					else
						break;
					Queue[i+1] = data;
					Pri[i+1] = p;
					rear++;
				}
			}
		}
		else
		{
			for(i = rear;i>=front;i--)
			{
				if(p<Pri[i])
				{
					Queue[i+1] = Queue[i];
					Pri[i+1] = Pri[i];	
				}
				else
					break;
			}
			Queue[i+1] = data;
			Pri[i+1] = p;
			rear++;
		}	
	}
}

void print() 
{
	int i;
	printf("\nThe Priority Queue : ");
	for(i=front;i<=rear;i++)
	{
		printf("\nElement = %d\tPriority = %d",Queue[i],Pri[i]);
	}
}

int dequeue() 
{
	if(front == -1)
	{
		printf("\nQueue is Empty!");
	}	
	else
	{
		printf("\nDeleted Element = %d\t It's Priority = %d",Queue[front],Pri[front]);
		if(front==rear)
			front = rear = -1;
		else
			front++;
	}
}

int main()
{
	int choice,n,i,data,p;
	printf("Enter Your Choice :- ");
	do{
		printf("\n\n1. Insert the Data in Queue\n2. Show the Data in Queue \n3. Delete the data from the Queue\n0. Exit :- ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nHow many numbers do you want to enter? : ");
				scanf("%d",&n);
				printf("\nEnter your data and Priority of data : ");
				i=0;
				while(i<n)
				{
					scanf("%d %d",&data,&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nInvalid Choice");

		}
	}while(choice!=0);
    return 0;
}
