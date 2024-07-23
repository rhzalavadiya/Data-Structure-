#include<stdio.h>
#include<conio.h>
#define n 5
void Menu()
{
    printf("\n1) Push");
    printf("\n2) Pop");
    printf("\n3) Peep");
    printf("\n4) Display");
    printf("\n5) Exit");
    printf("\n Enter Your Choice...");
}
int IsFull(int *top)
{
    if(*top==n-1)
	return 1;
    else
	return 0;
}
int IsEmpty(int *top)
{
	if(*top==-1)
		return 1;
	else
		return 0;
}
void Push(int stack[],int *top,int ele)
{
	if(IsFull(top)==1)
	{
		printf("\nStack is Full..");
		return;
	}
	*top+=1;
	stack[*top]=ele;
}
int Pop(int stack[],int *top)
{
	int tmp;
	if(IsEmpty(top)==1)
	{
		printf("\nEmpty");
		return -1;
	}
	tmp=stack[*top];

	(*top)-=1;
	return tmp;
}
int Peep(int stack[],int *top)
{
	int tmp;
	if(IsEmpty(top)==1)
	{
		printf("\nEmpty");
		return -1;
	}
	tmp=stack[*top];
	return tmp;
}
void Display(int  stack[],int *top)
{
	while(!IsEmpty(top))
	{
		printf("| %d |\n",Pop(stack,top));
	}
}
void main()
{
	int ch,ele;
	int stack[n],top;
	top=-1;
	do
	{
	     clrscr();
	     Menu();
	     scanf("%d",&ch);
	     switch(ch)
	     {
		case 1:
			printf("\nEnter element......");
			scanf("%d",&ele);
			Push(stack,&top,ele);
		break;
		case 2:
			ele=Pop(stack,&top);
			if(ele==-1)
				printf("\nPoped element is..%d",ele);
			else
				printf("\nPoped element is..%d",ele);
		break;
		case 3:
		    ele=Peep(stack,&top);
			if(ele!=-1)
				printf("\nPeep element is..%d",ele);
		break;
		case 4:
			  Display(stack,&top);
		break;
		case 5:
		break;
	     }
	     getch();
	}while(ch!=5);
}