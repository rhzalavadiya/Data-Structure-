#include<stdio.h>
#include<conio.h>
#define max 10

void addq(int *,int,int *,int *);
int delq(int *,int *,int *);
void display(int *);

void main()
{
	int arr[max];
	int i,front,rear;
	clrscr();
	front=rear=-1;
	for(i=0;i<max;i++)
		arr[i]=0;

	addq(arr,14,&front,&rear);
	addq(arr,15,&front,&rear);
	addq(arr,16,&front,&rear);
	addq(arr,17,&front,&rear);
	printf("\n elements in circular queue");
	display(arr);

	delq(arr,&front,&rear);
	delq(arr,&front,&rear);
	printf("\n elements are deleted");
	display(arr);


}
void addq(int *arr,int item, int *front,int *rear)
{
	if((*rear==max-1 && *front==0 ) || (*rear+1==*front))
	{
		printf("\n queue is full");
		return;
	}
	if(*rear==max-1)
	{
	       *rear=0;
	}
	else
	{
		(*rear)++;
		arr[*rear]=item;

	 }
	if(*front==-1)
		*front=0;
}
int delq(int *arr,int *front,int *rear)
{
	int data;
	if(*front==-1)
	{
		printf("\n queue is empty");
		return NULL;
	}
	data=arr[*front];
	arr[*front]=0;
	if(*front==*rear)
	{
		*front==-1;
		(*rear)++;
	}
	else
	{
		if(*front==max-1)
			*front=0;
	}
	else
	{
		(*front)++;
	}
}

void display(int *arr)
{
}