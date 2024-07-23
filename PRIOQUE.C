#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 5
struct data
{
	char data[max];
	int prno;
	int ord;
}
struct pque
{
	struct data d[max];
	int front,rear;
};
void initpque(struct pque *pq)
{
	int i;
	pq->front=pq->rear=-1;
	for(i=0;i<max;i++)
	{
		pq->d[i].prno=pq->d[i].ord=0;
	}
}

void add(struct pque *pq,struct dara dt)
{
	struct data tmp;
	int i,j;
	if(pq->rear==max-1)
	{
		printf("\n queue is full");
		getch();
		return;
	}
	pq->rear++;
	pq->d[pq->rear]=dt;
	if(pq->front==-1)
		pq->front=0;

	for(i=pq->front;i<pq->rear;i++)
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
					if(pq->d[i].ord > pq->d[j].ord)
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

struct data delete(struct pque *pq)
{
	struct data t;
	strcpy(t.job,"");
	t.prno=0;
	t.ord=0;
	if(pq->front==-1)
	{
		printf("\n queue is empty\n");
		return t;
	 }
	 t=pq->d[pq->front];
	 pq->d[pq->front=t;

	 if(pq->front==pq->rear)
		pq->front=pq->rear=-1;
	 else
		pq->front++;

	 return t;
}
void main()
{
	struct pque q;
	struct data dt,tmp;
	int i,j=0;
	for(i=0;i<max;i++)
	{




