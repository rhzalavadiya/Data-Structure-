#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Poly
{
	int off,exp;
	struct Poly *next;
	struct Poly *prev;
}poly;
void Append(poly **st,int off,int exp)
{
    poly *tmp,*r;
    r=*st;
    tmp=malloc(sizeof(poly));
    tmp->off=off;
    tmp->exp=exp;
    if(*st==NULL|| (*st)->exp<exp)
    {
	*st=tmp;
	tmp->prev=NULL;
	tmp->next=r;
    }
    else
    {
       while(r!=NULL)
       {
	   if(r->exp>=exp)
	   {
	       if(r->next==NULL || r->next->exp<exp)
		       {
		   tmp->next=r->next;
		   r->next=tmp;
		   tmp->prev=r;
		   return;
	       }
	   }
	   r=r->next;
	   tmp->prev=r;
       }
    }
}
void Menu()
{
	printf("\n1)Append List 1");
	printf("\n2)Append List 2");
	printf("\n3)Add");
	printf("\n4)Display");
	printf("\n5)Exit");
	printf("\nEnter Your Choice....");
}
void Display(poly *st)
{
	while(st!=NULL)
	{
		if(st->off>0)
			printf("%5dx^%d",st->off,st->exp);
		else
			printf("%5dx^%d",st->off,st->exp);
		st=st->next;
	}
	printf("\b=0");

}
void Add(poly *p,poly *q,poly **r)
{
	if(p==NULL && q==NULL)
	{
		printf("\nInvalid....");
		return;
	}
	while(p!=NULL && q!=NULL)
	{
		if(p->exp > q->exp)
		{
			Append(r,p->off,p->exp);
			p=p->next;
		}
		else if(p->exp < q->exp)
		{
			Append(r,q->off,q->exp);
			q=q->next;
		}
		else
		{
			Append(r,p->off+q->off,p->exp);
			p=p->next;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		Append(r,p->off,p->exp);
		p=p->next;
	}
	while(q!=NULL)
	{
		Append(r,q->off,q->exp);
		q=q->next;
	}
}
void main()
{
	poly *st,*st1,*st2;
	int ch,off,exp;
	st=NULL;
	st1=NULL;
	st2=NULL;
	do
	{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    printf("\nEnter Officent : - ");
			    scanf("%d",&off);
			    printf("\nEnter Exponent : - ");
			    scanf("%d",&exp);
			    Append(&st,off,exp);
			break;
			case 2:
			    printf("\nEnter Officent : - ");
			    scanf("%d",&off);
			    printf("\nEnter Exponent : - ");
			    scanf("%d",&exp);
			    Append(&st1,off,exp);
			break;
			case 3:
				Add(st,st1,&st2);
			break;
			case 4:
				Display(st);
				printf("\n+\n");
				Display(st1);
				printf("\n\n");
				printf("\n------------------------\n");
				Display(st2);
			break;
			case 5:
			break;
			default:
				printf("\nWrong Choice....");
		}
		getch();
	}
	while(ch!=5);
}