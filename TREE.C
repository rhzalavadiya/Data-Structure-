#include <stdlib.h>
#include<stdio.h>
#include <conio.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
void createTree(node **tree,int item)
{
	if(*tree == NULL)
	{
		*tree = malloc(sizeof(node));
		(*tree)->data = item;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else
	{
		if( (*tree)->data > item)
			createTree( &((*tree)->left),item);
		else
			createTree( &((*tree)->right),item);
	}
}
void  preOrder(node *tree)
{
	if( tree!=NULL)
	{
		printf("%5d",tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
void  inOrder(node *tree)
{
	if( tree!=NULL)
	{
		inOrder( tree->left);
		printf("%5d",tree->data);
		inOrder(tree->right);
	}
}
void  postOrder(node *tree)
{
	if( tree!=NULL)
	{
		postOrder( tree->left);
		postOrder( tree->right);
		printf("%5d",tree->data);

	}
}
void  determineHeight(node *tree, int *height)
{
	int left_height, right_height;
	if( tree == NULL)
		*height = 0;
	else
	{
		determineHeight(tree->left, &left_height);
		determineHeight(tree->right, &right_height);
		if( left_height > right_height)
			*height = left_height + 1;
		else
			*height = right_height + 1;
	}
}
int  totalNodes(node *tree){
	if( tree == NULL)
		return 0;
	else
	return( totalNodes(tree->left) + totalNodes(tree->right) + 1 );
}
int  internalNodes(node *tree)
{
	if( (tree==NULL)  || (tree->left==NULL  && tree->right==NULL))
	return 0;
	else
	return( internalNodes(tree->left) + internalNodes(tree->right) + 1 );
}
int  externalNodes(node *tree)
{
	if( tree==NULL )
	return 0;
	else if( tree->left==NULL  && tree->right==NULL)
	return 1;
	else
	return( externalNodes(tree->left) + externalNodes(tree->right));
}
void  removeTree(node **tree){
	if( (*tree) != NULL){
		removeTree( &(*tree)->left );
		removeTree( &(*tree)->right );
		free( *tree );
	}
}
node **  searchElement(node **tree, int item){
	if( ((*tree)->data == item) || ( (*tree) == NULL) )
		return tree;
	else if( item < (*tree)->data)
		return searchElement( &(*tree)->left, item);
	else
		return searchElement( &(*tree)->right, item);
}
void  findSmallestNode(node *tree){
	if( tree==NULL || tree->left==NULL)
		printf("%5d",tree->data);// cout<< tree->data;
	else
		findSmallestNode( tree->left);
}
node * find_Insucc(node *curr)
{
	node *succ=curr->right; //Move to the right sub-tree.
	if(succ!=NULL){
		while(succ->left!=NULL)	//If right sub-tree is not empty.
			succ=succ->left; //move to the left-most end.
	}
	return(succ);
}
void  findLargestNode(node *tree){
	if( tree==NULL || tree->right==NULL)
	      printf("%5d",tree->data);	//cout<<tree->data;
	else
		findLargestNode(tree->right);
}
void  deleteNode(node *tree,int item){
	node *curr=tree,*succ,*pred;
	int flag=0,delcase,item1;
	while(curr!=NULL && flag!=1)
	{
		if(item < curr->data){
			pred = curr;
			curr = curr->left;
		}
		else if(item > curr->data){
			pred = curr;
			curr = curr->right;
		}
		else{ //curr->data = item
			flag=1;
		}
	}
	if(flag==0){
		printf("\nItem does not exist : No deletion\n");
		getch();
		return;
	}
	if(curr->left==NULL && curr->right==NULL)
		delcase=1; //Node has no child
	else if(curr->left!=NULL && curr->right!=NULL)
		delcase=3; //Node contains both the child
	else
		delcase=2; //Node contains only one child
	if(delcase==1){
		if(pred->left == curr) //if the node is a left child
			pred->left=NULL; //set pointer of its parent
		else
			pred->right=NULL;
		free(curr); //Return deleted node to the memory bank.
	}
	if(delcase==2){
		if(pred->left==curr){ //if the node is a left child
			if(curr->left==NULL)
				pred->left=curr->right;
			else
				pred->left=curr->left;
		}
		else{ //pred->right=curr
			if(curr->left==NULL)
				pred->right=curr->right;
			else
				pred->right=curr->left;
		}
		free(curr);
	}
	if(delcase==3){
		succ = find_Insucc(curr); //Find the in_order successor
					  //of the node.
		item1 = succ->data;
		deleteNode(tree,item1);  //Delete the inorder successor
		curr->data = item1; //Replace the data with the data of
				   //in order successor.
	}
}
void menu()
{
	printf("*****BINARY SEARCH TREE OPERATIONS*****\n\n");
		printf("--Binary Tree and Binary Search Tree common operations--\n");
		printf("1) Create Tree\n");
		printf("2) Traversal\n");
		printf("3) Height of Tree\n");
		printf("4) Total Nodes\n");
		printf("5) Internal Nodes \n");
		printf("6) External Nodes \n");
		printf("7) Remove Tree\n");
		printf("\n--Only Binary Search Tree Operations--\n");
		printf("8)  Insert Node\n");
		printf("9)  Search Node\n");
		printf("10) Find Smallest Node\n");
		printf("11) Find Largest Node\n");
		printf("12) Delete Node\n");
		printf("13) Exit\n");
}
void main()
{

	int choice,i;
	node *tree=NULL;
	int height=0,total=0,n,item;
	node **tmp;
	while(1){
		clrscr();
		menu();
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : //Create Tree
				printf("\n\n--Creating Tree--");
				printf("\nHow many nodes u want to enter : ");
				scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter value : ");
			       scanf("%d",&item);
				createTree(&tree,item);
			}
			break;

			case 2 : //All Traversals
				printf("\n\nInorder Traversal : ");
				inOrder(tree);

				printf("\n\nPre-order Traversal : ");
				preOrder(tree);

				printf("\n\nPost-order Traversal : ");
				postOrder(tree);
				getch();
				break;

			case 3 : //Determining Height of Tree
				determineHeight(tree,&height);
				printf("\n\nHeight of Tree : =%d",height);
				getch();
				break;

			case 4 : //Total nodes in a tree
				total=totalNodes(tree);
				printf("\n\nTotal Nodes : %d",total);
				getch();
				break;

			case 5 : //Internal nodes in a tree
				total=internalNodes(tree);
			       printf("\n\nInternal Nodes :%d ",total);
				getch();
				break;

			case 6 : //External nodes in a tree
				total=externalNodes(tree);
				printf("\n\nExternal Nodes : %d",total);
				getch();
				break;

			case 7 : //Remove Tree from memory
				removeTree(&tree);
				printf("\n\nTree is removed from Memory");
				getch();
				break;

			case 8 : //Inserting a node in a tree
				printf("\n\n--Inserting Node in a tree--\n");
				printf("Enter value : ");
				scanf("%d",item);
				createTree(&tree,item);
				printf("\nItem is inserted\n");
				getch();
				break;

			case 9 : //Search element
				printf("\n\n--Search Element--\n");
			       printf("Enter item to searched : ");
				scanf("%d",&item);
				tmp = searchElement(&tree,item);
				if( (*tmp) == NULL)
					printf("\nSearch Element Not Found");
				else
					printf("\nSearch Element was Found");
				getch();
				break;

			case 10 : //Find Smallest Node
			       printf("\n\nSmallest Node is :  ");
				findSmallestNode(tree);
				getch();
				break;

			case 11 : //Find Largest Node
				printf("\n\nLargest Node is :  ");
				findLargestNode(tree);
				getch();
				break;

			case 12 : //Deleting a node from a tree
				printf("\n\n--Deleting a Node from a tree--\n");
				printf("Enter value : ");
				scanf("%d",item);
				deleteNode(tree,item);
				break;

			case 13 : exit(1);
		}//end of switch
	}
}