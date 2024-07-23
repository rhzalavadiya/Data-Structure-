#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}list;
void Menu()
{
	printf("\n1) Append");
	printf("\n2) Add At Begining");
	printf("\n3) Add Between");
	printf("\n4) Delete");
	printf("\n5) Search");
	printf("\n6) Reverse");
	printf("\n7) Dispaly");
	printf("\n8) Exit");
	printf("\nEnter Your Choice.....");
}
void Append(list **st,int n)
{
    list *tmp,*r;
    tmp=malloc(sizeof(list));
    tmp->data=n;
    tmp->next=NULL;
    if(*st==NULL)
    {
	*st=tmp;
	return;
    }
    r=*st;
    while(r->next!=NULL)
	r=r->next;
    r->next=tmp;
}
void Display(list *st)
{
	while(st!=NULL)
	{
		printf("%5d",st->data);
		st=st->next;
	}

}
void AddBetween(list *st,int loc,int n)
{
	int i;
	list *tmp,*r;
	r=st;
	for(i=1;i<loc;i++)
	{
		if(r==NULL)
			return;
		r=r->next;
	}
	tmp=malloc(sizeof(list));
	tmp->data=n;
	tmp->next=r->next;
	r->next=tmp;
}
void AddBegin(list **st,int n)
{
	list *tmp;
	tmp=malloc(sizeof(list));
	tmp->data = n;
	tmp->next = *st;
	*st = tmp;
}
void Delete(list **st,int n)
{
	list *tmp,*old;
	tmp=*st;
	while(tmp!=NULL)
	{
		if(tmp->data==n)
		{
			if(tmp==*st)
				*st=tmp->next;
			else
				old->next=tmp->next;
			free(tmp);
			return;
		}
		else
		{
			old=tmp;
			tmp=tmp->next;
		}
	}
	printf("\nData Not Found...");
}
int Search(list *st,int n)
{
	list *tmp;
	tmp=st;
	while(tmp!=NULL)
	{
		if(tmp->data==n)
			return 1;
		tmp=tmp->next;
	}
	return 0;
}
void Reverse(list **st)
{
	list *q,*r,*s;
	q=*st;
	r=NULL;
	while(q!=NULL)
	{
		s=r;
		r=q;
		q=q->next;
		r->next=s;
	}
	*st=r;
}
void main()
{
	list *st=NULL;
	int n,ch,loc,a;
	do
	{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    printf("\nEnter Data : - ");
			    scanf("%d",&n);
			    Append(&st,n);
			break;
			case 2:
			    printf("\nEnter Data on Beging : - ");
			    scanf("%d",&n);
			    AddBegin(&st,n);
			break;
			case 3:
			    printf("\nEnter Location to add Data : - ");
			    scanf("%d",&loc);
			    printf("\nEnter Data : - ");
			    scanf("%d",&n);
			    AddBetween(st,loc,n);
			break;
			case 4:
			    printf("\nEnter Data to Delete : - ");
			    scanf("%d",&n);
			    Delete(&st,n);
			break;
			case 5:
			    printf("\nEnter Data for Search : - ");
			    scanf("%d",&n);
			    a=Search(st,n);
			    if(a>0)
				printf("\nData Found....");
			    else
				printf("\nData Not  Found...");
			break;
			case 6:
			    Reverse(&st);
			    Display(st);
			break;
			case 7:
			    printf("\nData is : - ");
			    Display(st);
			break;
			case 8:
			break;
			default:
				printf("\nYou Enter Wrong Choice...");
		}
		getch();
	}
	while(ch!=8);
}