#include<stdio.h>
#define size 5
void Enqueue(int);

int Dequeue();
int queue[size];
void display();
int Front=-1,Rear=-1;
int main()
{
	int ch,e,p;

	do
	{
		printf("---MENU---\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element :");
				scanf("%d",&e);
				Enqueue(e);
				break;
			case 2:
				p=Dequeue();
				printf("Deleted element is %d",p);
				break;
			case 3:
				display();
				break;
		}
	}while(ch!=4);
				
	return 0;
}

void Enqueue(int element)
{
	if((Rear==size-1 && Front==0) || ((Rear+1)%size==Front))
	{
		printf("Overflow\n");
	}
	else if(Rear==-1)
	{
		Rear=0,Front=0;
	}
	else
	{
		Rear=(Rear+1)%size;
		queue[Rear]=element;
	}
}

int Dequeue()
{
	int e; 
	if(Front==-1)
	{
		printf("Underflow");
	}
	else
	{
		e=queue[Front];
		if(Front==Rear)
		{
			Front=-1;
			Rear=-1;
		}
		else
		{
			Front=(Front+1)%size;
		}
	}
	return e;
} 

void display()
{
	for(int i=Front;i<Rear;i++)
	{
		printf("%d ",queue[i]);
	}
}
		
