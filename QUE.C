#include<stdio.h>
#include<conio.h>
#define m 5
void Menu()
{
	clrscr();
	printf("\n1)Enque \n2)Deque \n3)Display \n4)Exit");
	printf("\nEnter Your choice....");
}
int Enque(int qu[],int n,int *f,int *r)
{
    if(*f==0 && *r==m-1)
    {
	printf("\nQueue is Full");
	return 0;
    }
    ++(*r);
    qu[*r]=n;
    if(*f==-1)
	++(*f);
    return 1;
}
int Deque(int qu[],int *f,int *r)
{
	int n;
	if(*f==-1)
	{
		return -1;
	}
	if(*f==*r)
	{
		n=qu[*f];
		*f=-1;
		*r=-1;
	}
	else
	{
		n=qu[*f];
		(*f)++;
	}
	return n;
}
void Display(int qu[],int front,int rear)
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("| %d | ",qu[i]) ;
	}
}
void main()
{
    int qu[m],front,rear;
    int ch,n;
    front=rear=-1;
    do
    {
	Menu();
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    printf("Enter Element....");
		    scanf("%d",&n);
		    if(Enque(qu,n,&front,&rear)==1)
			printf("\nData insert...");
		break;
		case 2:
		n=Deque(qu,&front,&rear);
		if(n==-1)
			printf("\nQueue is Empty...");
		else
			printf("\nDeleted Element is : - %d",n);
		break;
		case 3:
			Display(qu,front,rear);
		break;
		case 4:
		break;
		default:
			printf("\nWrong Choice");
	}
	getch();
    }   while(ch!=4);
}