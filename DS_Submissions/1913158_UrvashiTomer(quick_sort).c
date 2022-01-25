/******Implementation of Quicksort****/

#include<stdio.h>
#include<conio.h>

int Quick_sort(int ar[], int p, int r);
int Partition(int ar[], int p, int r);


int main()
{
	int i, n, ar[20];
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	
	printf("\nEnter %d elements to be sorted :\n",n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&ar[i]);
	}
	Quick_sort(ar, 0, n-1);
	printf("\nThe sorted elements are : ");
	for(i=0; i<n; i++)
	{
		printf("%d, ",ar[i]);
	}
	return 0;
}

int Quick_sort(int ar[], int p, int r)
{
	int q;
	if(p<r)
	{
		q=Partition(ar, p, r);
		Quick_sort(ar, p, q-1);
		Quick_sort(ar, q+1, r);
	}
}

int Partition(int ar[], int p, int r)
{
	int i, j, x,temp;
	x = ar[r];
	i = p-1;
	for(j = p; j<=r-1; j++)
	{
		if(ar[j] <= x)
		{
			i++;
			temp = ar[j];
			ar[j] = ar[i];
			ar[i] = temp;
		}
	}
	temp = ar[i+1];
	ar[i+1] = ar[r];
	ar[r] = temp;
	return i+1;
}

