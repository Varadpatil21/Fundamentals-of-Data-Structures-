#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	char data;
	struct stack *next;
}*top=NULL;

int precedence(char);
void push(char);
char pop();

int main()
{
	char infix[20],postfix[20];
	int i=0,j=0;
	printf("Enter infix expression :");
	scanf(" %s",infix);
	while(infix[i]!='\0')
	{
		if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else
		{
			if(top==NULL)
			{
				push(infix[i]);
			}
			else
			{
				while(precedence(infix[i])<=precedence(top->data) && top!=NULL)
				{
					postfix[j++]=pop();
				}
				push(infix[i]);
			}
		}
		i++;
	}

	while(top!=NULL)
	{
		postfix[j++]=pop();
		//top=top->next;
		
	}
	postfix[j]='\0';
	printf(" %s",postfix);
	return 0;
}


int precedence(char op)
{
	switch(op)
	{
		case '^':
			return 3;
			break;
		case '/':
			
			return 2;
			break;
		case '*':
			return 2;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
    }
}

void push(char op)
{
	struct stack *new;
	new=(struct stack*)malloc(sizeof(struct stack));
	new->data=op;
	new->next=NULL;
	if(top==NULL)
	{
		top=new;
	}
	else
	{
		new->next=top;
		top=new;
	}
}
char pop()
{
	struct stack *temp;
	int ch;
	if(top==NULL)
	{
		printf("Overflow");
	}
	else if(top->next==NULL)
	{
		temp=top;
		ch=top->data;
		top=NULL;
		free(temp);
	}
	else
	{
		temp=top;
		ch=top->data;
		top=top->next;
		free(temp);
	}
	return ch;
}

