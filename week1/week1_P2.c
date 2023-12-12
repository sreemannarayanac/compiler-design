# include <stdio.h>

// Write a program to read a square matrix and transpose it without using temporary matrix
// (Use functions - main contains only readmatrix(), transpose(), printmatrix())

void readmatrix(int a[10][10], int n)
{
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void transpose(int a[10][10], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp; 
        }
    }
}

void printmatrix(int a[10][10], int n)
{
    int i, j;
    printf("The matrix is:\n");
    for (i = 0; i < n; i++)
    {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    readmatrix(a, n);
    printf("\nThe matrix is:\n");
    printmatrix(a, n);
    transpose(a, n);
    printf("\nThe transpose of the matrix is:\n");
    printmatrix(a, n);
    return 0;
}