#include<stdio.h>
int main()
{
	int i,j,row1,row2,col1,col2,count1=0,k1=0,count2=0,k2=0;
        printf("Enter no of rows of first matrix:");
	scanf("%d",&row1);
	printf("Enter no of columns of first matrix:");
	scanf("%d",&col1);
	printf("Enter no of rows of first matrix:");
	scanf("%d",&row2);
	printf("Enter no of columns of first matrix:");
	scanf("%d",&col2);
	int mat1[row1][col1],mat2[row2][col2];
	printf("Enter elements of first matrix\n");
        for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",&mat1[i][j]);
			if(mat1[i][j]==0)
     				count1++;
			else
				k1++;
				
		}
	}
	printf("Enter elements of second matrix\n");
	for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			scanf("%d",&mat1[i][j]);
			if(mat2[i][j]==0)
     				count2++;
			else
				k2++;
				
		}
	}
        if(count1>(row1*col1)/2 && count2>(row2*col2)/2 )
	{
		printf("Sparse Matrix\n");
		int s[k1][3],p=0,q[k2][3],c=0;
		for(i=0;i<row1;i++)
	     	{
			for(j=0;j<col1;j++)
			{
				if(mat1[i][j]!=0)
	 			{
					s[p][0]=i;
					s[p][1]=j;
					s[p][2]=mat1[i][j];
					p++;
				}
			}
		}
		for(i=0;i<row2;i++)
	     	{
			for(j=0;j<col2;j++)
			{
				if(mat2[i][j]!=0)
	 			{
					q[p][0]=i;
					q[p][1]=j;
					q[p][2]=mat2[i][j];
					c++;
				}
			}
		}
		for(i=0;i<p;i++)
		{
			printf("%d %d %d\n",s[i][0],s[i][1],s[i][2]);
		}
		printf("\n");
		for(i=0;i<c;i++)
		{
			printf("%d %d %d\n",q[i][0],q[i][1],q[i][2]);
		}
		
	
		
	}
	else
		printf("Not a sparse matrix");
			
	return 0;
}
	
	
