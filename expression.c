#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct tree 
{
	char data;
	struct tree *left, *right;
};
int top =-1,top1=-1;
struct tree *stack[20];
struct tree *stack1[15];

void push(struct tree* root) 
{
	top=top+1;
	stack[top] = root;
	//printf("\nstack data: %p",stack[top]);
}
struct tree * pop(void)
{
	return (stack[top--]);
}
void inorder(struct tree *root)
{

	if(root==NULL)
	{
		return;
	}
	else
	{
		if (root != NULL)
		{
			inorder(root->left);
		}
		printf(" %c", root->data);
		inorder(root->right);
	}
}
void inorder1(struct tree *root)
{
    struct tree *curr=root;
    while(curr!=NULL || top1!=-1)
    {
        while(curr!=NULL)
        {
            stack1[++top1]=curr;
            curr=curr->left;
        }
        curr=stack1[top1];
        top1--;
        printf("%c",curr->data);
        curr=curr->right;
    }
}

    

void operand(char b) 
{
	struct tree *root;
	root = (struct tree*) malloc(sizeof(struct tree));
	root->data = b;
	root->left = NULL;
	root->right = NULL;
	/*printf("\n%c", root->data);
	printf("\noperend Address:%p", root);*/
	push(root);
}
void operators(char a) 
{
	struct tree *root;
	root = (struct tree*) malloc(sizeof(struct tree));
	root->data = a;
	//printf("\noperator data:%c",root->data);
	root->right = pop();
	root->left = pop();
	push(root);
}
int main()
{
	int i=0, p, k, ans;
	char s[20];
	printf("Enter the expression in postfix form \n");
	scanf("%s", s);
	while(s[i]!='\0')
	{
		if(isalnum(s[i]))
		{
			printf("\noperand:%c",s[i]);
			operand(s[i]);
		}
		else
		{
			printf("\noperator:%c",s[i]);
			operators(s[i]);
		}
		i++;
	}
	printf("\nThe inorder traversal of the tree is \n");
	inorder1(stack[top]);
	return 0;
}
