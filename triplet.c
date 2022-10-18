#include<stdio.h>
int main()
{
	int i,j,row,col,count=0,k=0;
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
			else
				k++;
				
		}
	}
        int s[k][3],p=0;
        for(i=0;i<row;i++)
     	{
		for(j=0;j<col;j++)
		{
			if(mat[i][j]!=0)
 			{
				s[p][0]=i;
				s[p][1]=j;
				s[p][2]=mat[i][j];
				p++;
			}
		}
	}
	printf("\tR \tC \tV\n");
        for(i=0;i<k;i++)
	{
		printf("\t%d \t%d \t%d\n",s[i][0],s[i][1],s[i][2]);
        }
		
	return 0;
}
	
	
