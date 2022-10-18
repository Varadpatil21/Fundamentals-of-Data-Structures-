#include<stdio.h>
int main()
{
	int i,j,row,col,count=0;
        printf("Enter no of rows:");
	scanf("%d",&row);
	printf("Enter no of columns:");
	scanf("%d",&col);
	int mat[row][col];
        for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j]==0)
     				count++;
		}
	}
        if(count>(row*col)/2)
 		printf("Sparse Matrix");
	else
		printf("Not a Sparse matrix");
	return 0;
}
	
	
