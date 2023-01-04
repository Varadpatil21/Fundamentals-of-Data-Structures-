#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct hospital
{
    int sr, age;
    long long int Mo_no;
    char name[10], disease[10];
    struct hospital *next;
};
int count = 0;
struct hospital *head = NULL;
struct hospital *insert()
{
    struct hospital *ter, *new;
    char r[10];
    new = (struct hospital *)malloc(sizeof(struct hospital));
    ter = head;
    printf("Please Enter details of Patient...\n");
    printf("\nEnter Sr. No.:");
    scanf("%d", &new->sr);
    printf("\nEnter Name:");

    scanf(" %s",new->name);
    //strcpy(new->name,r);
    printf("\nEnter Age:");
    scanf("%d", &new->age);
    printf("\nEnter Mobile No.:");
    scanf(" %lld",&new->Mo_no);
    printf("\nEnter a disease:");
    scanf(" %s", new->disease);
  // printf("%s",new->name);
    printf("%d %s %d %lld %s\n",new->sr,new->name,new->age,new->Mo_no,new->disease);

    if (count == 0)
    {
        new->next = NULL;
        head=new;
    }
    else if (count == 1)
    {
        head->next = new;
        new->next = NULL;
    }
    else
    {
        while (ter->next != NULL)
        {
            ter = ter->next;
        }
        ter->next = new;
        new->next = NULL;
    }
    count++;
    return head;
   
}
struct hospital *Delete()
{
    int data, rlog;
    struct hospital *temp, *r, *rt;
    
    printf("Enter the serial no. of patient that has to be deleted from record\n");
    scanf("%d", &data);
    temp = head;
    if(data==1)
    {
        head=head->next;
        free(temp);
        r=head;
        while(r!=NULL)
        {
            r->sr=r->sr-1;
            r=r->next;
        }
    }
    else if(data==count)
    {
        while(temp->next!=NULL)
        {
            rt=temp;
            temp=temp->next;
        }
        rt->next=NULL;
        free(temp);
    }
    else
    {
       while(temp->next!=NULL)
        {
            rt=temp;
            temp=temp->next;
        }
        rt->next=temp->next;
        free(temp); 
        r=rt->next;
        while(r->next!=NULL)
        {
            r->sr=r->sr-1;
            r=r->next;
        }
    }
    return head;
}
void search()
{
    char n[10];
    struct hospital *ten;
    ten = head;
    int c;
    printf("Enter name you want to search:");
    scanf(" %s",n);
    while(ten->next!=NULL)
    {
        c=strcmp(n,ten->name);
        if(c==0)
            break;
        ten=ten->next;
    }  
    printf("Searching for a patient...\n");
    int a;
    for( a=1;a<8;a++)
    {
        sleep(1);
        printf("...");
    }  
    printf("\nPatient Found\n");
    printf("Details are\n");
    printf("Sr.No.\tName\tAge\tMo.No.\tDisease\n");
    printf("----------------------------------------\n");
    printf("%d %s %d %lld %s\n",ten->sr,ten->name,ten->age,ten->Mo_no,ten->disease);

   
}

void display()
{
    struct hospital *temp;
    temp=head;
    printf("Sr.No.\tName\tAge\tMo.No.\tDisease\n");
    printf("----------------------------------------\n");
    while(temp!=NULL)
    {
        printf("%d\t%s\t%d\t%lld\t%s\n",temp->sr,temp->name,temp->age,temp->Mo_no,temp->disease);
        temp=temp->next;
    }

}

void displaya()
{
    int ch;
    printf("Age group\n");
    printf("1.Childrens\n2.Adults\n3.Senior Citizens\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    struct hospital *temp;
    temp=head;
    if(ch==1)
    {
        while(temp!=NULL)
        {
            if(temp->age<18)
            {
                printf("%d\t%s\t%d\t%lld\t%s\n",temp->sr,temp->name,temp->age,temp->Mo_no,temp->disease);
            }
            temp=temp->next;
        }
    }
    if(ch==2)
    {
        while(temp!=NULL)
        {
            if(temp->age>18 && temp->age<60)
            {
                printf("%d\t%s\t%d\t%lld\t%s\n",temp->sr,temp->name,temp->age,temp->Mo_no,temp->disease);
            }
            temp=temp->next;
        }
    }
   else
    {
        while(temp!=NULL)
        {
            if(temp->age>60)
            {
                printf("%d\t%s\t%d\t%lld\t%s\n",temp->sr,temp->name,temp->age,temp->Mo_no,temp->disease);
            }
            temp=temp->next;
        }
    }

}
int main()
{
    int ch,y;
	do
	{
		printf("----------------------------------------\n");
        printf("Welcome to Hospital Management System\n");
        printf("----------------------------------------\n");
		printf("1.Insert a Patient\n2.Delete a Patient\n3.Search for a patient\n4.Display\n5.Display records as per age\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=insert();
				break;
			case 2:
				head=Delete();
				break;
			case 3:
				search();
				break;
			case 4:
				display();
				break;
            case 5:
                displaya();
                break;
		}
		printf("\nDo you want to continue(0/1):");
		scanf("%d",&y);
	}while(y==1);
    return 0;
}



 
   


     
