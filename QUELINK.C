#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Queue{
	int data;
	struct Queue *next;
}qu;
void Menu()
{
	clrscr();
	printf("\n1)Enque \n2)Deque \n3)Display \n4)Exit");
	printf("\nEnter Your choice....");
}
int Enque(int n,qu **f,qu **r)
{
    qu *tmp;
    tmp=malloc(sizeof(qu));
    tmp->data=n;
    tmp->next=NULL;
    if(tmp==NULL)
    {
	printf("\nQueue is full..");
	return 0;
    }
    if(*f==NULL)
    {
	*f=tmp;
	*r=tmp;
	return -1;
    }
    (*r)->next=tmp;
    *r=tmp;
    return 1;

}
int Deque(qu **f,qu **r)
{
	int n;
	if(*f==NULL)
	{
		*r=NULL;
		return -1;
	}
	n=(*f)->data;
	*f=(*f)->next;
	return n;
}
void Display(qu *front)
{
	while(front!=NULL)
	{
		printf("| %d | ",front->data) ;
		front=front->next;
	}
}
void main()
{
    qu *front,*rear;
    int ch,n;
    front=rear=NULL;
    do
    {
	Menu();
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    printf("Enter Element....");
		    scanf("%d",&n);
		    if(Enque(n,&front,&rear)==1)
			printf("\nData insert...");
		break;
		case 2:
		n=Deque(&front,&rear);
		if(n==-1)
			printf("\nQueue is Empty...");
		else
			printf("\nDeleted Element is : - %d",n);
		break;
		case 3:
			Display(front);
		break;
		case 4:
		break;
		default:
			printf("\nWrong Choice");
	}
	getch();
    }   while(ch!=4);
}