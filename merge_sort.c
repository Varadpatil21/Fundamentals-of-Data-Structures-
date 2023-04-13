#include<stdio.h>

void Merge(int A[],int b,int m,int e)
{
	int i,j,k;
	int n1=m-b+1;
	int n2=e-m;
	int left[n1],right[n2];
	printf("%d %d\n",n1,n2);
	for(int i=0;i<n1;i++)
	{
		left[i]=A[b+i];
	}
	for(int j=0;j<n2;j++)
	{
		right[j]=A[m+1+j];
	}
	i=0,j=0,k=b;
	while(i<n1 && j<n2)
	{
		if(left[i]>right[j])
		{
			A[k]=right[j];
			k++;
			j++;
		}
		else
		{
			A[k]=left[i];
			k++;
			i++;
		}	
	}
	while(i<n1)
	{
		A[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k]=right[j];
		j++;
		k++;
	}
	
	
}


void MergeSort(int A[],int b,int e)
{
	if(b<e)
	{
		int m=(b+e)/2;
		MergeSort(A,b,m);
		MergeSort(A,m+1,e);
		Merge(A,b,m,e);
	}
}
	

int main()
{
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int A[n]; 
	for(int i=0;i<n;i++)
	{
		printf("Enter number:");
		scanf("%d",&A[i]);
	}
	MergeSort(A,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
		

