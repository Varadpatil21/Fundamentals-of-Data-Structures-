#include<stdio.h>
#define n 5
#define capacity 12

float basedonprofit(float p[],float w[],float x[])
{
	float temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(p[j]<p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	float tp=0.0,W=0.0;
	for(int i=0;i<n;i++)
	{
		if(W+w[i]<=capacity)
		{
			x[i]=1;
			W=W+w[i];
			
		}
		else
		{
			x[i]=(capacity-W)/w[i];
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		tp=tp+p[i]*x[i];
	}
	return tp;
	

}	

float basedonweight(float p[],float w[],float x[])
{
	float temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(w[j]>w[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	float total=0.0,W=0.0;
	for(int i=0;i<n;i++)
	{
		if(W+w[i]<=capacity)
		{
			x[i]=1;
			W=W+w[i];
		}
		else
		{
			x[i]=(capacity-W)/w[i];
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		total=total+p[i]*x[i];
	}
	return total;
	

}	

float basedonratio(float p[],float w[],float x[])
{
	float temp;
	float r[10];
	for(int i=0;i<n;i++)
	{
	     r[i]=p[i]/w[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(r[j]<r[j+1])
			{
			     temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	float total=0.0,W=0.0;
	for(int i=0;i<n;i++)
	{
		if(W+w[i]<=capacity)
		{
			x[i]=1;
			W=W+w[i];
		}
		else
		{
			x[i]=(capacity-W)/w[i];
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		total=total+p[i]*x[i];
	}
	return total;
	

}	




int main()
{
	float p[10],w[10],x[10];
	printf("Enter profit\n");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&p[i]);
	}
	printf("Enter weight associated with profit\n");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	for(int i=0;i<n;i++)
	{
		x[i]=0.0;
	}

	float tp=basedonweight(p,w,x); 
	float total=basedonprofit(p, w,x);
	float total1=basedonratio(p, w,x);
     
	printf("based on profit: : %f\n",total);
     printf("based on weight: %f\n",tp);
     printf("based on profit by weight ratio: %f\n",total1);
     
	
	
		
}	
