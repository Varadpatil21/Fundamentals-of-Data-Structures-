#include<stdio.h>

int main()
{
	int v,e=1,min,c,d,s,r,total=0;
	printf("Enter no. of vertices :");
	scanf("%d",&v);
	int a[v][v],visited[10];
	for(int i=0;i<v;i++)
		visited[i]=0;
	printf("Enter adjacency matrix\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
				a[i][j]=999;
		}
	} 
	visited[0]=1;
	while(e<v)
	{
		for(int i=0,min=999;i<v;i++)
		{	
			for(int j=0;j<v;j++)
			{
				if(a[i][j]<min)
				{
					if(visited[i]!=0)
					{
						min=a[i][j];
						c=s=i;
						d=r=j;
					}
				}
			}
			if(visited[s]==0 || visited[r]==0)
			{
				total=total+min;
				printf("\nEdge is (%d %d) with cost %d",c,d,min);
				visited[d]=1;
			}
			a[c][d]=a[d][c]=999;
		}
		e++;

			
		
	}
	printf("\nTotal cost of MST is %d",total);
	return 0;
}
