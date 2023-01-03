#include<stdio.h>
#include<stdlib.h>

struct database
{
	int id;
	char name[10];
	int salary;
	char Mo_No[10];
	struct database *prv,*next;
};

struct database *head=NULL;

void insert()
{
	struct database *new,*temp;
	new=(struct database *)malloc(sizeof(struct database));
	printf("Enter employee id:");
	scanf("%d",&new->id);
	printf("Enter employee name:");
	scanf(" %s",new->name);
	printf("Enter employee Salary:");
	scanf("%d",&new->salary);
	printf("Enter employee Mobile No.:");
	scanf(" %s",new->Mo_No);
	new->prv=new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
		new->prv=temp;
	}
}

void displayf()
{
	struct database *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t%s\t%d\t%s\n",temp->id,temp->name,temp->salary,temp->Mo_No);
		temp=temp->next;
	}
}

void displayb()
{
	struct database *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d\t%s\t%d\t%s\n",temp->id,temp->name,temp->salary,temp->Mo_No);
		temp=temp->prv;
	}
		
}

struct database* delete()
{
	int i,count=1;
	printf("Enter id you want to delete:");
	scanf("%d",&i);
	struct database *temp;
	temp=head;
	while(temp->id!=i)
	{
		count++;
		temp=temp->next;
		
	}
	if(count==1)
	{
		head=head->next;
		head->prv=NULL;
		free(temp);
	}
	else
	{
		temp->prv->next=temp->next;
		free(temp);
	}
	return head;
}

void modify()
{
	int i,ch;
	struct database *temp;
	temp=head;
	printf("Enter id you want to modify:");
	scanf("%d",&i);
	while(temp->id!=i)
	{
		temp=temp->next;
	}
	printf("You want to modify\n");
	printf("1.Salary\n2.Mobile no.\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter updated salary :");
		scanf("%d",&temp->salary);
	}
	else
	{
		printf("Enter updated Mobile No. :");
		scanf("%s",temp->Mo_No);
	}
}
	
	


	
	


int main()
{
	int ch,y;
	do
	{
		printf("------MENU-------\n");
		printf("1.Insert a record\n2.Delete a record\n3.Modify a record\n4.Display a list forward\n5.Display a list backward\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				head=delete();
				break;
			case 3:
				modify();
				break;
			case 4:
				displayf();
				break;
			case 5:
				displayb();
				break;
		}
		printf("Do you want to continue(0/1):");
		scanf("%d",&y);
	}while(y==1);

		
	return 0;
}
