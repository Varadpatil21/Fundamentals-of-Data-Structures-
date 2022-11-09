#include<stdio.h>

#include<stdlib.h>

struct abc
{
	char name[20];
	int PRN;
	struct abc *prv;
	struct abc *next;
};

void insertS(struct abc *head)
{
	struct abc *new;
	new=(struct abc*)malloc(sizeof(struct abc));
	printf("Enter secretary name :");
	scanf("%s",new->name);
	printf("Enter PRN No. :");
	scanf("%d",&new->PRN);
	new->prv=NULL;
	new->next=NULL;
	head->next=new;
	new->prv=head;
	
}

void Display(struct abc *head)
{
	struct abc *temp;
	temp=head;
	printf("\tName \tPRN No.\n"); 
	while(temp!=NULL)
	{
		printf("\t%s \t%d\n",temp->name,temp->PRN); 
		temp=temp->next;
	}
}

void insertM(struct abc *head)
{
	struct abc *new,*p;
	new=(struct abc*)malloc(sizeof(struct abc));
	printf("Enter member name :");
	scanf("%s",new->name);
	printf("Enter PRN No. :");
	scanf("%d",&new->PRN);
	new->prv=NULL;
	new->next=NULL;
	/*new->next=head->next;
	new->next->prv=new;
	head->next=new;
	new->prv=head;*/
	p=head->next;
	head->next=new;
	new->prv=head;
	new->next=p;
	p->prv=new;
}

struct abc* deleteP(struct abc *head)
{
    struct abc *temp;
    temp=head;
    head->next->prv=NULL;
    head=head->next;
    free(temp);
    return head;
}
void deleteM(struct abc *head)
{
    struct abc *p,*q;
    p=head->next;
    q=(head->next)->next;
    free(p);
    head->next=q;
    q->prv=head;
    
}

void deleteS(struct abc *head)
{
    struct abc *p;
    p=head;
    //q=head->next;
    while(p->next!=NULL)
    {
        p=p->next;
        //q=q->next;
    }
    p->prv->next=NULL;
    
    free(p);
    //p->next=NULL;
    
}

void countM(struct abc *head)
{
    struct abc *temp;
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("No. of members in a club %d",count);
}

void reverse(struct abc *head,struct abc *temp)
{
	if(temp!=NULL)
	{
		printf("%s %d\n",temp->name,temp->PRN);
		temp=temp->prv;
		reverse(head,temp);
	}
}
	
	

	



int main()
{
    int ch;
	struct abc *head,*temp;
	head=(struct abc*)malloc(sizeof(struct abc));
	printf("Enter President name :");
	//gets(head->name);
	scanf("%s",head->name);
	printf("Enter PRN No.:");
	scanf("%d",&head->PRN);
	head->prv=NULL;
	head->next=NULL;
	
	insertS(head);
	
	do
	{
		printf("\n1.insert member\n2.Delete Member\n3.Delete President\n4.Delete Secretary\n5.No of members\n6.Display members\n7.reverse");
		printf("Enter your choice");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				insertM(head);
				break;
			case 2:
			    deleteM(head);
			    break;
			case 3:
			    head=deleteP(head);
			    break;
			case 4:
			    deleteS(head);
			    break;
			case 5:
			    countM(head);
			    break;
			case 6:
			    Display(head);
			    break;
			case 7:
			    temp=head;
			    while(temp->next!=NULL)
			    {
				temp=temp->next;
			    }
			    
			    reverse(head,temp);
			   break;
		}
	}
	while(ch!=8);
	
			    
				
	return 0;
}




   
   
