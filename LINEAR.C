#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define S 50
void Menu()
{
	printf("\n1.Linear Search");
	printf("\n2.Binary Search(Recursion)");
	printf("\n3.Binary Search(Non Recursion)");
	printf("\n4.Bubble Sort");
	printf("\n5.Selection Sort");
	printf("\n6.Insertion Sort");
	printf("\n7.Shell Sort");
	printf("\n8.Quick Sort");
	printf("\n9.Heap Sort");
	printf("\n10.Merge Sort");
	printf("\n11.Radix Sort");
	printf("\n12.Exit");
}
void ReadArray(int *a,int s)
{
	int i;
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);
}
void WriteArray(int *a,int s)
{
	int i;
	for(i=0;i<s;i++)
		printf("%5d",a[i]);
}
int Linear(int *a,int s,int no)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(a[i]==no)
		return i+1;
	}
	return 0;
}
void BubbleSort(int *a,int s)
{
	int i,j,temp;
	for(i=0;i<s;i++)
	{
		for(j=0;j<s-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int Binary(int *a,int s,int search)
{
	int min,max,mid,found=0;
	min=0;
	max=s-1;
	while(max>=min)
	{
		mid=(min+max)/2;
		if(a[mid]==search)
		{
			found=1;
			break;
		}
		else if(search<a[mid])
			max=mid-1;
		else
			min=mid+1;
	}
	return found;
}
void SelectionSort(int *a,int s)
{
	int i,j,min,temp;
	for(i=0;i<s-1;i++)
	{
		min=i;
		for(j=i+1;j<s;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
int binarySearch(int *arr, int s, int key)
{
    int mid,low,high;
    low=0;
    high=s-1;
    if (low > high)
	return -1;
    mid = low + (high - low) / 2;
    if (arr[mid] == key)
	return mid;
    else if (arr[mid] < key)
	return binarySearch(arr, s, key);
    else
	return binarySearch(arr,s, key);
}
void InsertionSort(int *a,int s)
{
	int i,j,index;
	for(i=1;i<s;i++)
	{
		j=i;
		index=a[i];
		while(j>0 && a[j-1]>index)
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=index;
	}
}
void ShellSort(int *a,int s)
{
	int i,j,inc,tmp;
	inc=3;
	while(inc>0)
	{
		for(i=0;i<s;i++)
		{
			j=i;
			tmp=a[i];
			while((j>=inc)&&(a[j-inc]>tmp))
			{
				a[j]=a[j-inc];
				j=j-inc;
			}
			a[j]=tmp;
		}
		inc=inc/2;
	}
}
void QuickSort(int *a,int left,int right)
{
	int pivot,left_r,right_r;
	left_r=left;
	right_r=right;
	pivot=a[left];
	while(left<right)
	{
		while(a[right]>=pivot && left!=right)
			right--;
		if(left!=right)
		{
			a[left]=a[right];
			left++;
		}
		while(a[left]<pivot && left!=right)
			left++;
		if(left!=right)
		{
			a[right]=a[left];
			right--;
		}
	}
	a[left]=pivot;
	pivot=left;
	left=left_r;
	right=right_r;
	if(left<pivot)
		QuickSort(a,left,pivot-1);
	if(pivot<right)
		QuickSort(a,pivot+1,right);
}
void BuildHeap(int *a,int s1)
{
	int i,elt,s,f;
	for(i=1;i<s1;i++)
	{
		elt=a[i];
		s=i;
		f=(s-1)/2;
		while(s>0 && a[f]<elt)
		{
			a[s]=a[f];
			s=f;
			f=(s-1)/2;
		}
		a[s]=elt;
	}
}
void HeapSort(int *a,int n)
{
	int i,elt,s,f,iv;
	BuildHeap(a,n);
	for(i=n-1;i>0;i--)
	{
		iv=a[i];
		a[i]=a[0];
		f=0;
		if(i==1)
			s=-1;
		else
			s=1;
		if(i>2 && a[2]>a[1])
			s=2;
		while(s>=0 && iv<a[s])
		{
			a[f]=a[s];
			f=s;
			s=2*f+1;
			if((s+1<=i-1) && (a[s]<a[s+1]))
				s++;
			if(s>i-1)
				s=-1;
		}
		a[f]=iv;
	}
}
void Merge(int *a,int *tmp,int left,int mid,int right)
{
	int i,le,ele,tmp_pos;
	le=mid-1;
	tmp_pos=left;
	ele= right-left+1;
	while((left<=le) && (mid<=right))
	{
		if(a[left]<=a[mid])
			tmp[tmp_pos++]=a[left++];
		else
			tmp[tmp_pos++]=a[mid++];
	}
	while(left<=le)
		tmp[tmp_pos++]=a[left++];
	while(mid<=right)
		tmp[tmp_pos++]=a[mid++];
	for(i=0;i<=ele;i++)
	{
		a[right]=tmp[right];
		right=right-1;
	}
}
void MergeSort(int *a,int *tmp,int left,int right)
{
	int mid;
	if(right>left)
	{
		mid=(right+left)/2;
		MergeSort(a,tmp,left,mid);
		MergeSort(a,tmp,mid+1,right);
		Merge(a,tmp,left,mid+1,right);
	}
}
int getMax(int *a, int s)
{
    int i;
    int mx = a[0];
    for (i = 1; i < s; i++)
    {
	if (a[i] > mx)
	    mx = a[i];
    }
    return mx;
}
int DigitCount(int n)
{
	int i=0;
	while(n>0)
	{
		i++;
		n=n/10;
	}
	return i;
}
void init(int *x[],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			x[i][j]=0;
	}
}
int getPos(int a,int k)
{
	int pos;
	int c=1;
	while(c<=k)
	{
		pos=a%10;
		a=a/10;
		c++;
	}
	return pos;
}
void RadixSort(int *a,int n)
{
	int *sa[10];
	int max=getMax(a,n);
	int dig=DigitCount(max);
	int y,z,pos,i,k,s,r,c;
	int counter[10];
	for(i=0;i<10;i++)
	{
		sa[i]=(int *)malloc(n*sizeof(int *));
		counter[i]=0;
	}
	for(k=1;k<=dig;k++)
	{
		for(i=0;i<n;i++)
		{
			pos=getPos(a[i],k);
			sa[pos][counter[pos]++]=a[i];
		}
		s=0;
		for(r=0;r<10;r++)
			for(c=0;c<n && counter[r]!=0;c++)
			{
				a[s++]=sa[r][c];
				counter[r]--;
			}

	}
}
void countSort(int *a, int n, int exp)
{
    int *output;
    int i, count[10] = { 0 };
    output=(int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
	count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
	count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
	output[count[(a[i] / exp) % 10] - 1] = a[i];
	count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
	a[i] = output[i];
}
void radixsort(int *a, int n)
{
    int m = getMax(a, n);
    int i;
    for (i = 1; m / i > 0; i *= 10)
	countSort(a, n, i);
}
void main()
{
	int s,no,a1,ch,result;
	int *a,*tmp;
	do
	{
		clrscr();
		Menu();
		printf("\nEnter your Choice....\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			printf("\nEnter element for search....\n");
			scanf("%d",&no);
			a1=Linear(a,s,no);
			if(a1>0)
				printf("\nAvalable on %d  and %d",a1,no);
			else
				printf("\nnot Avalable");
		break;
		case 2:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			printf("\nEnter element for search....\n");
			scanf("%d",&no);
			BubbleSort(a,s);
			result = binarySearch(a,s,no);
			if (result != -1)
				printf("Element %d found at index %d\n", no, result);
			else
				printf("Element %d not found in the array\n",no);
		break;
		case 3:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			printf("\nEnter element for search....\n");
			scanf("%d",&no);
			BubbleSort(a,s);
			if(Binary(a,s,no))
				printf("\nElement Founded");
			else
				printf("\nElement not Founded");
		break;
		case 4:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			BubbleSort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
			break;
		case 5:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			SelectionSort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 6:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			InsertionSort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 7:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			ShellSort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 8:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			QuickSort(a,0,s-1);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 9:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			HeapSort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 10:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			tmp=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			MergeSort(a,tmp,0,s-1);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 11:
			printf("Enter array size....\n");
			scanf("%d",&s);
			a=(int *)malloc(s*sizeof(int));
			printf("Enter Array Element...\n");
			ReadArray(a,s);
			printf("Array Element is...\n");
			WriteArray(a,s);
			RadixSort(a,s);
		     //	radixsort(a,s);
			printf("\nAfter Sorting Array Element is...\n");
			WriteArray(a,s);
		break;
		case 12:
		break;
		default:
			printf("Invalid Choice....");
		}
		getch();
	}
	while(ch!=12);
}