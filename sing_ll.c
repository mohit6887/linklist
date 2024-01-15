#include<stdio.h>
#include<stdlib.h>


struct node {
	int info;
	struct node *link;
};

struct node *createlist(struct node *start);
struct node *insertinbeginning(struct node *start,int data);
void insertatend(struct node *start,int data);
void search(struct node *start,int x);
void countnodes(struct node *start);
void insertafter(struct node *start,int data,int x);
struct node *insertbefore(struct node *start,int data,int x);
struct node *insertatposition(struct node *start,int data,int k);
struct node *deletenode(struct node *start,int data);
struct node *reverselist(struct node *start);
void displaylist(struct node *start);




int main()
{
	struct node *start=NULL;
	int choice,data,x,k;
	start = createlist(start);
	while(1)
	{
		printf("\n");
		printf("1. Display list \n");
		printf("2.Count the the number of nodes \n");
		printf("3. Search for an element\n");
		printf("4. Insert in empty list /Insert in beginning of the list \n");
		printf("5. Insert the node at the end of the list \n");
		printf("6. Insert a node after a specified node \n");
		printf("7. Insert a node before a specified node \n");
		printf("8. Insert a node at given position \n");
		printf ("9. Delete a node \n");
		printf("10. Reverse the list \n");
		printf("11. Quit\n\n");
		printf("Enter your choice :");
		scanf("%d",&choice);

		if(choice ==11)
			break;
		switch(choice)
		{
			case 1:
				displaylist(start);
				break;
			case 2:
				countnodes(start);
				break;
			case 3:
				printf("Enter the element to be searched :");
				scanf("%d",&data);
				search(start,data);
				break;
			case 4:
				printf("Enter the element to be inserted");
				scanf("%d",&data);
				start=insertinbeginning(start,data);
				break;
			case 5:
				printf("Enter the element to be inserted :");
				scanf("%d",&data);
				insertatend(start,data);
				break;
			case 6:
				printf("Enter the element to be inserted :");
				scanf("%d",&data);
				printf("Enter the element after which to insert :");
				scanf("%d",&x);
				insertafter(start,data,x);
				break;
			case 7:
				printf("Enter the element to be inserted :");
				scanf("%d",&data);
				printf("ENter the element before which to insert :");
				scanf("%d",&x);
				start=insertbefore(start,data,x);
				
				break;
			case 8:
				printf("Enter the element to be inserted :");
				scanf("%d",&data);
				printf("Enter the position at which to insert:");
				scanf("%d",&k);
				start=insertatposition(start,data,k);
				break;
			case 9:
				printf("Enter the elemnet to be deleted :");
				scanf("%d",&data);
				start=deletenode(start,data);
				break;
			case 10:
				start=reverselist(start);
				break;
			default:
				printf("Wrong choice \n");


		}
	
	}

	
}


struct node *createlist(struct node *start)
{
	int i,n,data;
	printf("Enter the number of the nodes:\n");
	scanf("%d",&n);
	if(n==0)
	{
		return start;
	}
	printf("Enter the first number to be inserted :");
	scanf("%d",&data);
	start=insertinbeginning(start,data);
	for(i=2;i<=n;i++)
	{
		printf("ENter the next element to be inserted :");
		scanf("%d",&data);
		insertatend(start,data);
	}
	return start;
}

struct node *insertinbeginning(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}

void insertatend(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->link!=NULL)
		{
			p=p->link;
		}
	p->link=temp;
	temp->link=NULL;

}


void displaylist(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty \n");
		return;
	}
	printf("List is : ");
	p=start;
	while(p!=NULL)
	{
		printf("%d  ",p->info);
		p=p->link;
	}
	printf("\n");
}

struct node *deletenode(struct node *start,int data)
{
	struct node *temp, *p;
	if(start ==NULL)
	{
		printf("List is emply \n");
		return start;
	}
	if(start->info==data)
	{
		temp=start;
		start=start->link;
		free(temp);
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
			break;
		p=p->link;
	}
	if(p->link ==NULL)
	{
		printf("Element  %d  not in list \n\n",data);
	}
	else
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
	return start;
}

struct node *reverselist(struct node *start)
{
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=start;
	while(ptr !=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start =prev;
	return start;
}

void countnodes(struct node *start)
{
	int n=0;
	struct node *p=start;
	while(p!=NULL)
	{
		n++;
		p=p->link;

	}
	printf("NUmber of  nodes in the list =%d\n",n);
}
void search(struct node *start,int x)
{
	struct node *p;
	int position=1;
	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			break;
		position++;
		p=p->link;
	}
	if(p==NULL)
		printf("%d not found in list \n",x);
	else
		printf("%d is at position %d\n",x,position);

}

void insertafter(struct node *start,int data,int x)
{
	struct node *temp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info ==x)
		{
			break;
		}
		p=p->link;
	}
	if(p==NULL)
	{
		printf("%d not present in the list \n",x);

	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
}
struct node *insertbefore(struct node *start,int data,int x)
{
	struct node *temp , *p;
	if(start=NULL)
	{
		printf("List is empty \n");
		return start;
	}
	if(x==start->info)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==x)
			break;
		p=p->link;
	}
	if(p->link==NULL)
	{
		printf("%d not present in the list \n ",x);
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
	return start;

}

struct node *insertatposition(struct node *start,int data,int k)
{
	struct node *temp,*p;
	int i;
	if(k==1)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	for(i=1;i<k-1 && p!=NULL;i++)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		printf("You can insert only upto %d th positon \n\n",i);
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
	return start;
}
