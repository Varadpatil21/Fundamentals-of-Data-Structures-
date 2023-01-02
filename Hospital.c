#include <stdio.h>

#include <stdlib.h>
struct hospital
{
    int sr, age;
    long int Mo_no;
    char name[30], disease[30];
    struct hospital *next;
};
int count = 0;
struct hospital *head = NULL;
struct hospital *insert()
{
    struct hospital *ter, *new;
    new = (struct hospital *)malloc(sizeof(struct hospital));
    ter = head;

    /*
    scanf("%d%d%d %s %s",&new->sr,&new->age,&new->Mo_no,new->name,new->disease);*/
    scanf("%d", &new->sr);
    scanf("%d", &new->age);
    scanf("%ld",&new->Mo_no);
    
    scanf(" %s", new->name);
    scanf(" %s", new->disease);
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
   /* if (data != 1)
    {
        for (int x = 1; x < data; x++)
        {
            r = temp;
            temp = temp->next;
        }
    }
    if (temp->next != NULL && data != 1)
    {
        r->next = temp->next;
        rlog = temp->sr;
        rt = temp;
        for (int x = rlog; x < count; x++)
        {
            rt = rt->next;
            rt->sr--;
        }
        free(temp);
    }
    else if (data == 1)
    {
        head = head->next;
        rt = temp;
        for (int x = 1; x < count; x++)
        {
            rt = rt->next;
            rt->sr--;
        }
        free(temp);
    }
    else if (temp->next == NULL)
    {
       head=NULL;
        free(temp);
    }*/
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
    struct hospital *ten;
    ten = head;
    ten = (struct hospital *)malloc(sizeof(struct hospital));

    int a = 0;
    printf("Enter the age of person\n");
    scanf("%d", &a);
    while (ten->next != NULL)
    {
        if (ten->age == a)
        {
            printf("%d\n", ten->sr);
            printf("%d\n", ten->age);
            for (int i = 0; i < 10; i++)
            {
                printf("%d", ten->Mo_no);
            }
            printf(" \n %s \n", ten->name);
            printf(" %s \n", ten->disease);
        }
        ten = ten->next;
    }
    if (ten->age == a)
    {
        printf("%d\n", ten->sr);
        printf("%d\n", ten->age);
        for (int i = 0; i < 10; i++)
        {
            printf("%d", ten->Mo_no);
        }
        printf(" \n %s \n", ten->name);
        printf(" %s \n", ten->disease);
    }
}

void display()
{
    struct hospital *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d %s %d %ld %s\n",temp->sr,temp->name,temp->age,temp->Mo_no,temp->disease);
        temp=temp->next;
    }

}
int main()
{
    // Write C code here
    printf("Hello world\n");
    head = (struct hospital *)malloc(sizeof(struct hospital));
    head = insert();
    display();
    head = insert();
     display();
    head = insert();
     display();
    head = insert();
     display();
    head = Delete();
     display();
    //search();
    return 0;
}
