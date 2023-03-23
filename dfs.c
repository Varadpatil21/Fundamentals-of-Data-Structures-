#include<stdio.h>
#define n 5
int A[n][n];
int visited[n];
int stack[20];
int top=-1;
void DFS(int v)
{
	visited[v]=1;5
	printf("%d ",v);
	for(int i=0;i<n;i++)
	{
		if(A[v][i]==1 && !visited[i])
		{
			
			DFS(i);
		}
	}
		
}

void DFS1(int v)
{
	visited[v]=1;
	printf("%d ",v);
	for(int i=0;i<n;i++)
	{
		if(A[v][i]==1 && !visited[i])
		{
			top++;
			stack[top]=i;
			DFS1(i);
			break;
		}
	}	
	while(top!=-1)
	{
		for(int i=0;i<n;i++)
		{
			if(A[stack[top]][i]==1 && !visited[i])
				DFS1(i);
			else
				top--;
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
	top++;
	stack[top]=s;
	DFS1(s);
}
