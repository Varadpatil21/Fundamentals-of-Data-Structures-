#include<stdio.h>
void swap(int *x,int *y)
{
     int temp;
	temp=*x;
         *x=*y;
         *y=temp;
}

void sort(int a[],int n)
{
	int temp;
        for(int i=0;i<n-1;i++)
        {
          for(int j=0;j<n-i-1;j++)
          {
     		if(a[j]>a[j+1])
                {
                   swap(&a[j],&a[j+1]);
                }
	}
     }
}

 

int main()
{
  int n1,n2,n;
  printf("How many numbers you want in first set:");
  scanf("%d",&n1);
  printf("How many numbers you want in second set:");
  scanf("%d",&n2);
  printf("How many numbers you want in universal set");
  scanf("%d",&n);
  int min=n1<n2?n1:n2;
  int s=n1+n2;
  int a[n1],b[n2],u[s];
  int U[n],I[min];
  printf("Enter elements for first set\n");
  for(int i=0;i<n1;i++)
  {
    scanf("%d",&a[i]);
  }
printf("Enter elements for second set\n");
  for(int i=0;i<n2;i++)
  {
    scanf("%d",&b[i]);
  }
printf("Enter elements for universal set\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&U[i]);
  }
  
 int i=0,j=0,k=0;
for(int i = 0; i < n1; i++)
       u[i] = a[i];
 for(int i = 0; i < n2; i++)     
        u[i + n1] = b[i];
  
  sort(u,s);
 
for(int i=0;i<s;i++)
{
   if(u[i]==u[i+1])
   {
    for(int j=i;j<s;j++)
    {
     u[j]=u[j+1];
     }
    s--;
   }
}

 for(int i=0;i<s;i++)
  {
    printf("%d ",u[i]);
  }
  //intersection 
  k=0;
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
       if(a[i]==b[j])
       {
           I[k]=a[i];
           k++;
        }
      }
    }
  for(int i=0;i<k;i++)
  {
    printf("%d ",I[i]);
  }



  return 0;

}
