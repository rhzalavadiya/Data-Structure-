#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}node;
void Menu()
{
    printf("\n1) Add..");
    printf("\n2) Display");
    printf("\n3) Exit");
    printf("\nEnter Your Choice.... : - ");
}
void Add(node **st,int n)
{
   node *tmp,*r;
   tmp=*st;
   r=malloc(sizeof(node));
   r->data=n;
   if(*st==NULL || (*st)->data > n)
   {
       *st=r;
       r->next=tmp;
   }
   else
   {
       while(tmp!=NULL)
       {
	  if(tmp->data<=n)
	  {
	      if((tmp->next == NULL) || (tmp->next->data>n))
	      {
		  r->next=tmp->next;
		  tmp->next=r;
		  return;
	      }
	  }
	  tmp=tmp->next;
       }
   }
}
void Display(node *st)
{
	while(st!=NULL)
	{
		printf("%5d",st->data);
		st=st->next;
	}

}
void main()
{
    int ch,n;
    node *st;
    st=NULL;
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
		Add(&st,n);
	    break;
	    case 2:
		Display(st);
	    break;
	    case 3:
	    break;
	    default:
		printf("\nInvalid Choice.......");
	}
	getch();
    }
    while(ch!=3);
}