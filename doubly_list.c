#include<stdio.h>

struct abc
{
	char name[20];
	int PRN;
	struct abc *prv;
	struct abc *next;
};

int main()
{
	struct abc *head;
	head=(struct abc*)malloc(sizeof(struct abc));
	printf("Enter President name :");
	gets(head->name);
	printf("Enter PRN No.:");
	scanf("%d",&head->PRN);
	head->prv=NULL;
	head->next=NULL;
	return 0;
}

