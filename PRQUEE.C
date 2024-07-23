#include <stdio.h>
#include <conio.h>
#define MAX 5
struct data
{
   char job[MAX];
   int prno;
   int ord;
};

struct pque
{
   struct data d[MAX];
   int front;
   int rear;
};
void initpque(struct pque *);
void add(struct pque *,struct data);
struct data delete(struct pque *);
void display(int*);

void main()
{
  struct pque q;
  struct data dt,tmp;
  int i,j=0;
  clrscr();
  //initialise data member
  initpque(&q);
  printf("Enter the job description(max 4 char) and its priority\n");
  printf("Lower the priority no,higher the priority\n");
  printf("Job     Priority\n");
  for(i=0;i<MAX;i++)
  {
     scanf("%s %d",&dt.job,&dt.prno);
     dt.ord=j++;
     add(&q,dt);
  }
  printf("\n");

  printf("\nProcess jobs priority wise\n");
  printf("Job     Priority\n");
  for(i=0;i<MAX;i++)
  {
    tmp=delete(&q);
    printf("%s\t%d\n",tmp.job,tmp.prno);
  }
  printf("\n");
  getch();
}

void initpque(struct pque *pq)
{
    int i;
    pq->front=pq->rear=-1;
     for(i=0;i<MAX;i++)
     {
	strcpy(pq->d[i].job,'\0');
	pq->d[i].prno=pq->d[i].ord=0;
     }
}

//adds an element to the queue
void add(struct pque *pq,struct data dt)
{
   struct data tmp;
   int i,j;
   if(pq->rear==MAX-1)
   {
     printf("\nQueue is Full");
     return;
   }
   pq->rear++;
   pq->d[pq->rear]=dt;
   if(pq->front==-1)
    pq->front=0;

    for(i=pq->front;i<=pq->rear;i++)
    {
       for(j=i+1;j<=pq->rear;j++)
       {
	  if(pq->d[i].prno>pq->d[j].prno)
	  {
	     tmp=pq->d[i];
	     pq->d[i]=pq->d[j];
	     pq->d[j]=tmp;
	  }
	  else
	  {
	     if(pq->d[i].prno==pq->d[j].prno)
	     {
		if(pq->d[i].ord>pq->d[i].ord)
		{
		   tmp=pq->d[i];
		   pq->d[i]=pq->d[j];
		   pq->d[j]=tmp;
		}

	     }
	  }
       }
    }
}

 //removes an element from queue
 struct data delete(struct pque *pq)
 {
     struct data t;
     strcpy(t.job,"");
     t.prno=0;
     t.ord=0;

     if(pq->front==-1)
     {
	printf("\nQueue is empty");
	return t;
     }
     t=pq->d[pq->front];
     pq->d[pq->front]=t;
     if(pq->front==pq->rear)
	pq->front=pq->rear=-1;
     else
     pq->front++;
     return t;
 }




