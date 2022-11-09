#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char c;
	struct stack *next;
};
struct stack *top=NULL;
int i=0;

void push(int n)
{
	char m;
	if(i==n-1)
		printf("Overflow\n");
	else
	{
		struct stack *new;
		new=(struct stack *)malloc(sizeof(struct stack));
		printf("Enter character :");
		scanf(" %c",&m);
		new->c=m;
		new->next=NULL;
		if(top==NULL)
		{
			top=new;
			i++;
		}
		else
		{
			new->next=top;
			top=new;
			i++;
                }
	}
}

char pop()
{
	struct stack *temp;
	temp=top;
	char b;
	temp=top;
	if(i==-1)
	{
		printf("Underflow\n");
		return -1;
	}
	else 
	{
		b=temp->c;
		top=top->next;
		free(temp);
		i--;
		return b;
	}
}

void display()
{
	struct stack *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%c\n",temp->c);
		temp=temp->next;
	}
}

char peek()
{
	char s=top->c;
	return s;
}
	

	
int main()
{
	int choice,n,y;
	char d,p;
	do
	{
		
		printf("1. Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number nodes you want :");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				d=pop();
				printf("Deleted element %c",d);
				break;
			case 3:
				p=peek()
				printf("Element present at top %c",p);
				break;
			case 4:
				display()
				break; 
		}
		printf("Do you want to continue :");
		scanf("%d",&y);
	}
	while(y==1);
}
				
				
				

