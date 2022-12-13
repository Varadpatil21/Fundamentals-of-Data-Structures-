#include <stdio.h>
#include <stdlib.h>


struct abc
{
	int data;
	struct abc *left,*right;
};

struct abc * insert(struct abc*,int);
struct abc * create(int);
void Inorder(struct abc *);
void search(struct abc *,int);

int main()
{
	struct abc *Root=NULL;
	int ch,d,key;
	do
	{
		printf("\n1. Insert\n2. Traverse\n3. Search");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&d);
				Root=insert(Root,d);
				break;
			case 2:
				printf("Inorder traversal is\n");
				Inorder(Root);
				break;
			case 3:
				printf("Enter element want to search :");
				scanf("%d",&key);
				search(Root,key);
		}		break;
	}while(ch!=4);

return 0;

}


struct abc * insert(struct abc* Root,int key)
{
	if(Root==NULL)
		return create(key);
	else if(key < Root->data)
		Root->left=insert(Root->left,key);
	else 
		Root->right=insert(Root->right,key);
	return Root;
}


struct abc *create(int key)
{
	struct abc *new;
	new=(struct abc*)malloc(sizeof(struct abc));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	return new;
}


void Inorder(struct abc * Root)
{
	if(Root==NULL)
		return;
	else
	{
		if(Root!=NULL)
			Inorder(Root->left);
		printf("%d ",Root->data);
		Inorder(Root->right);
	}
}

void search(struct abc *Root,int key)
{
	if(Root==NULL)
		printf("Tree not exist");
	else if(key==Root->data)
		printf("Element found");
	else if(key<Root->data)
		search(Root->left,key);
	else
		search(Root->right,key);
}



	
