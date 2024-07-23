#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define m 50
char out[m];
char st[m];
char input[m];
char *s,*t;
char ch;
int i,top;
void Initialize()
{
    clrscr();
    top=-1;
    strcpy(out,"");
    strcpy(st,"");
    i=0;
}
void SetExpression(char *str)
{
	s=str;
	i=strlen(s);
	*(out+i)='\0';
	t=out;
}
void Push(char c)
{
	if(top==m-1)
	   printf("stack is full ");
	else
	{
	     top++;
	     st[top]=c;
	}
}
char Pop()
{
    if(top==-1)
	return -1;
    else
    {
	char item=st[top];
	top--;
	return item;
    }
}
int Priority(char c)
{
	if(c=='^')
	    return 3;
	if(c=='*'||c=='/'||c=='%')
	     return 2;
	else if(c=='+'||c=='-')
	     return 1;
	else
	    return -1;
}
void Postfix()
{
	char opr;
	while(*(s))
	{
	    if(*(s)==' '||*(s)=='\t')
	    {
		s++;
		continue;
	    }

	    while(isdigit(*(s))||isalpha(*(s)))
	    {
		*(t)=*(s);
		s++;
		t++;
	    }
	    if(*(s)=='(')
	    {
		Push(*(s));
		s++;
	    }
	    if(*(s)=='+'||*(s)=='-'||*(s)=='*'||*(s)=='/'||*(s)=='%'||*(s)=='^')
	    {
		if(top!=-1)
		{
		    opr=Pop();
		    while(Priority(*(s))<=Priority(opr))
		    {
			*(t)=opr;
			t++;
			opr=Pop();
		    }
		    Push(opr);
		    Push(*(s));
		}
		else
			Push(*(s));
		s++;
	    }
	    if(*(s)==')')
	    {
		opr=Pop() ;
		while(opr!='(')
		{
		     *(t)=opr;
		     t++;
		     opr=Pop();
		}
		s++;
	    }
	}
	while(top!=-1)
	{
		opr=Pop();
		*(t)=opr;
		t++;
	}
	t++;
}
void Prefix()
{
	char opr;
	while(*(s))
	{
	    if(*(s)==' '||*(s)=='\t')
	    {
		s++;
		continue;
	    }
	    while(isdigit(*(s))||isalpha(*(s)))
	    {
		*(t)=*(s);
		s++;
		t++;
	    }
	    if(*(s)==')')
	    {
		Push(*(s));
		s++;
	    }
	    if(*(s)=='+'||*(s)=='-'||*(s)=='*'||*(s)=='/'||*(s)=='%'||*(s)=='^')
	    {
		if(top!=1)
		{
		    opr=Pop();
		    while(Priority(*(s))<=Priority(opr))
		    {
			*(t)=opr;
			t++;
			opr=Pop();
		    }
		    Push(opr);
		    Push(*(s));
		}
		else
			Push(*(s));
		s++;
	    }
	    if(*(s)=='(')
	    {
		opr=Pop() ;
		while(opr!=')')
		{
		     *(t)=opr;
		     t++;
		     opr=Pop();
		}
		s++;
	    }
	}
	while(top!=-1)
	{
		opr=Pop();
		*(t)=opr;
		t++;
	}
	t++;
}
void main()
{
       Initialize();
       printf("\n Enter Expression..........");
       gets(input);

       printf("\n1) Postfix \n2) Prefix  \n");
       ch=getchar();
       SetExpression(input);
       if(ch=='1')
       {
	Postfix() ;
	printf("\nPost fix is ... : ");
	puts(out);
       }
       if(ch=='2')
       {
		strrev(s);
		Prefix() ;
		strrev(out);
		printf("the Prefix Expression is....");
		puts(out);
       }
       getch();
}
