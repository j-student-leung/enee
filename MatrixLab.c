#include <stdio.h>
#include <stdlib.h>
void transpose(int m, int n, int A[10][10], int B[10][10])
{
        int x, y;
        for(x=0; x<n; x++)
        {
                for(y=0; y<m; y++)
                {
                        B[x][y]=A[y][x];
                }
        }
}
void multiply(int m, int n, int A[10][10], int B[10][10], int P[10][10])
{
        int x, y, z, a, product=0;
        FILE*fptr;
        fptr=fopen("text.txt", "w");
        for(x=0; x<m; x++)
        {
                for(y=0; y<m; y++)
                {
                        for(z=0; z<n; z++)
                        {
                                product+=A[x][z]*B[z][y];
                        }
                        P[x][y]=product;
                        /*printf("x=%d, y=%d, P[x][y]=%d\n", x, y, P[x][y]); this line was used as a debug line */
                        product=0;
                }
        }
}
int main()
{
        int A[10][10], x=0, y=0, m, n, a, b, c, d, e, f; /*all variables here are counting variables*/
        static int B[10][10], P[10][10];
        printf("*Note- program will truncate\nNumber of rows: ");
        scanf("%d", &m);
        printf("Number of columns: ");
        scanf("%d", &n);
        if(m>0 && m<=10) /*checking for valid entries*/
        {
                if(n>0 && n<=10) /*checking for valid entries*/
                {
                        for(x=0; x<m; x++)
                        {
                                for (y=0; y<n; y++)
                                {
                                        printf("Row %d\n Enter Value: ", x+1); /*printing row for clarity*/
                                        scanf("%d", &A[x][y]);
                                }
                        }
                        printf("Matrix A:\n");
                        for(a=0; a<m; a++)
                        {
                                for(b=0; b<n; b++)
                                {
                                        printf("%d\t", A[a][b]);
                                }
                                printf("\n");
                        }
                        transpose(m, n, A, B); /*function transposes orignial matrix*/
                        printf("Matrix B:\n");
                        for(c=0; c<n; c++) /*inverted parameters, as matrix B is matrix A, transposed*/
                        {
                                for(d=0; d<m; d++)
                                {
                                        printf("%d\t", B[c][d]);
                                }
                                printf("\n");
                        }
                        multiply(m, n, A, B, P); /*function multiplies transposed matrix with original*/
                        printf("Matrix P: \n");
                        for(e=0; e<m; e++)
                        {
                                for(f=0; f<m; f++) /*both loops go to the value of m, since the matrix bounds would be mxm*/
                                {
                                        printf("%d\t", P[e][f]);
                                }
                                printf("\n");
                        }
                }
                else
                        exit (1);
        }
        else
                exit(1);
        return 0;
}
