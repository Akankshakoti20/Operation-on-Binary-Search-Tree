#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node*llink;
	struct node*rlink;
};
typedef struct node*NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
}
NODE insert(int item,NODE root)
{
	NODE temp,cur,prev;
	int i;
	temp=getnode();
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	else
	{
		prev=NULL;
		cur=root;
		while(cur!=NULL)
		{
			prev=cur;
			cur=(temp->info<cur->info)?cur->llink:cur->rlink;
		}
		if(temp->info<prev->info)
			prev->llink=temp;
		else if(temp->info>prev->info)
			prev->rlink=temp;
		return root;
	}
}
void pre(NODE PRE)
{
	if(PRE!=NULL)
	{
		printf("%d\t",PRE->info);
		pre(PRE->llink);
		pre(PRE->rlink);
	}
}
void in(NODE IN)
{
	if(IN!=NULL)
	{
		in(IN->llink);
		printf("%d\t",IN->info);
		in(IN->llink);
	}
}
void post(NODE POST)
{
	if(POST!=NULL)
	{
		post(POST->llink);
		post(POST->rlink);
		printf("%d\t",POST->info);
	}
}
void Traversal(NODE root)
{
	NODE IN,PRE,POST;
	IN=root;
	PRE=root;
	POST=root;
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	printf("\n\nPreorder traversal...\n");
	pre(PRE);
	printf("\n\nInorder traversal...\n");
	in(IN);
	printf("\n\nPostorder traversal...\n");
	post(POST);
}
NODE search(NODE root)
{
	int item,i=0;
	NODE cur;
	printf("Enter the element to be searched\n");
	scanf("%d",&item);
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return root;
	}
	cur=root;
	while(cur!=NULL)
	{
		if(item==cur->info)
		{
			i++;
			printf("Found key %d in tree\n",cur->info);
		}
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(i==0)
		printf("Key not found\n");
		return root;
}
void main()
{
	int choice,item,n;
	NODE root=NULL;
	while(1)
	{
		printf("\n------------MENU-----------\n");
		printf("\n\t1.Create BST of N Integers\n");
		printf("\t2.Traversal\n");
		printf("\t3.search\n");
		printf("\t4.Exit\n");
		printf("\tEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter number elements:");
			       scanf("%d",&n);
					while(n>0)
					{
						printf("Enter the item to be inserted\n");
						scanf("%d",&item);
						root=insert(item,root);
						n--;
					}
					break;
			case 2:Traversal(root);
				break;
			case 3:search(root);
				break;
			case 4:return;
			default:printf("\n\tInvalid Choice...\n");
		}
	}
}
	

		





		


