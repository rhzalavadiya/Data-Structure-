#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}stack;
void Menu()
{
	printf("\n1) Push");
	printf("\n2) Pop");
	printf("\n3) Peep");
	printf("\n4) Dispaly");
	printf("\n5) Exit");
	printf("\nEnter Your Choice.....");
}
void Display(stack *top)
{
	while(top!=NULL)
	{
		printf("| %d |\n",top->data);
		top=top->next;
	}

}
void Push(stack **top,int n)
{
	stack *tmp;
	tmp=malloc(sizeof(stack));
	if(tmp==NULL)
	{
		printf("\nStack is Full");
		return;
	}
	tmp->data = n;
	tmp->next = *top;
	*top = tmp;
}
int Pop(stack **top)
{
	int d;
	stack *tmp;
	if(*top==NULL)
	{
		printf("\nStack is Empty");
		return -1;
	}
	tmp=*top;
	d=(*top)->data;
	*top=(*top)->next;
	free(tmp);
	return d;
}
int Peep(stack *top)
{
	if(top==NULL)
	{
		printf("\nStack is Empty");
		return -1;
	}
	top=top->data;
	return top;
}
void main()
{
	stack *top=NULL;
	int n,ch;
	do
	{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    printf("\nEnter Data  : - ");
			    scanf("%d",&n);
			    Push(&top,n);
			break;
			case 2:
			n=Pop(&top);
			if(n==-1)
				printf("\nPoped element is..%d",n);
			else
				printf("\nPoped element is..%d",n);
			break;
			case 3:
			   n=Peep(top);
			   if(n!=-1)
				printf("\nPeep element is..%d",n);
			break;
			case 4:
			  Display(top);
			break;
			case 5:
			break;
			default:
				printf("\nYou Enter Wrong Choice...");
		}
		getch();
	}
	while(ch!=5);
}