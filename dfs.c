#include<stdio.h>
#define n 5
int A[n][n];
int visited[n];

void DFS(int v)
{
	visited[v]=1;
	printf("%d ",v);
	for(int i=0;i<n;i++)
	{
		if(A[v][i]==1 && !visited[i])
		{
			
			DFS(i);
		}
	}
		
}

int main()
{
	int s;
	printf("Enter graph\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	printf("Enter the source point:");
	scanf("%d",&s);
	DFS(s);
}
