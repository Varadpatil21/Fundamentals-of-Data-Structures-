#include <stdio.h>

int main()
{
    int i, j, k, min, max, s[2][2], choice,flag=0;
    int a[3][3], *p = &a[0][0], b[3][3], *q = &b[0][0], c[3][3], *r = &c[0][0];
    int mat[3][3];
    int *l = &mat[0][0];
    do
    {
        printf("------MENU-------\n");
        printf("1. Addition\n 2. Multiplication\n 3. Saddle point\n 4. Saddle point(using pointers)\n 5. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter elements of 1st matrix\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    scanf("%d", (p + (i * 3) + j));
                }
            }
            printf("\n");
            printf("Enter elements of second matrix\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    scanf("%d", (q + (i * 3) + j));
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    *(r + (i * 3) + j) = *(p + (i * 3) + j) + *(q + (i * 3) + j);
                }
            }
            printf("Sum is\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("Enter elements of 1st matrix\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    scanf("%d", (p + (i * 3) + j));
                }
            }
            printf("\n");
            printf("Enter elements of second matrix\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    scanf("%d", (q + (i * 3) + j));
                }
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    c[i][j] = 0;

                    for (k = 0; k < 3; k++)
                    {
                        c[i][j] += *(p + (i * 3) + k) * *(p + (k * 3) + j);
                    }
                }
            }
            printf("Multiplication is\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("Enter elements of matrix\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    scanf("%d", &mat[i][j]);
                }
            }
            for (i = 0; i < 3; i++)
            {
                min = mat[i][0];
                for (j = 0; j < 3; j++)
                {
                    if (min >= mat[i][j])
                    {
                        min = mat[i][j];
                        s[0][0] = i;
                        s[0][1] = j;
                    }
                }
                j = s[0][1];
                max = mat[0][j];
                for (k = 0; k < 3; k++)
                {
                    if (max <= mat[k][j])
                    {
                        max = mat[k][j];
                        s[1][0] = k;
                        s[1][1] = j;
                    }
                }
                //printf("%d %d\n",min,max);
                if (min == max)
                {
                    if (s[0][0] == s[1][0] && s[0][1] == s[1][1])
                    {
                        printf("Saddle point is %d\n", min);
                    }
                }
            }
            break;
        case 4:

            printf("Enter elements of matrix\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    scanf("%d", (l + (i * 3) + j));
                }
            }
            printf("\n");
            /*for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d", *(l + (i * 3) + j));
                }
            }*/
            for (i = 0; i < 3; i++)
            {
                min = mat[i][0];
                for (j = 0; j < 3; j++)
                {
                    if (min >= *(l + (i * 3) + j))
                    {
                        min = *(l + (i * 3) + j);
                        s[0][0] = i;
                        s[0][1] = j;
                    }
                }
                j =s[0][1];
                max = *(l + (0 * 3) + j);
                for (k = 0; k < 3; k++)
                {
                    if (max <= *(l + (k * 3) + j))
                    {
                        max = *(l + (k * 3) + j);
                        s[1][0] = k;
                        s[1][1] = j;
                    }
                }
                //printf("%d %d",min,max);
                if (min == max)
                {
                    if (s[0][0] == s[1][0] && s[0][1] == s[1][1])
                    {
			flag=1;
                        printf("Saddle point is %d\n", min);
                    }
                }
            }
		printf("No saddle point");
        }
    } while (choice != 5);
    return 0;
}
    
