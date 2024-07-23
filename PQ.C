#include<stdio.h>
#include<conio.h>
#define m 5
typedef struct Pqueue{
	int data,pr;
}pq;
void Menu()
{
	clrscr();
	printf("\n1)Enque \n2)Deque \n3)Display \n4)Exit");
	printf("\nEnter Your choice....");
}
void Sort(pq q[])
{
	int i,j,temp;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-i-1;j++)
		{
			if(q[j].pr>q[j+1].pr)
			{
				temp=q[j].data;
				q[j].data=q[j+1].data;
				q[j+1].data=temp;
			}
		}
	}
}
int Enque(pq qu[],int n,int p,int *f,int *r)
{
    if(*f==0 && *r==m-1)
    {
	printf("\nQueue is Full");
	return 0;
    }
    ++(*r);
    qu[*r].data=n;
    qu[*r].pr=p;
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
void Display(pq qu[],int front,int rear)
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("| %d | ",qu[i].data);
	}
}
void main()
{
    int pr,front,rear;
    int ch,n;
    pq qu[m];
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
		    printf("Enter Priority....");
		    scanf("%d",&pr);
		    if(Enque(qu,n,pr,&front,&rear)==1)
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
			Sort(qu);
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