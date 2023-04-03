#include <stdio.h>

typedef struct matrix
{
    unsigned int mat[2][2];
}
matrix;

matrix mul(matrix a, matrix b)
{
    matrix ans;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int sum = 0;
            for (unsigned int k = 0; k < 2; k++)
            {
                sum += a.mat[i][k] * b.mat[k][j];
            }
            ans.mat[i][j] = sum;
        }
    }
    return ans;
}

matrix identity()
{
    matrix a;
    a.mat[0][0] = 1; a.mat[0][1] = 0;
    a.mat[1][0] = 0; a.mat[1][1] = 1;
    return a;
}

matrix power(matrix a, unsigned int n)
{
    if (n == 0)
    {
        return identity();
    }
    else
    {
        matrix b = power(a, n/2);
        if (n % 2 == 0)
        {
            return mul(b,b);
        }
        else
        {
            return mul(mul(b,b), a);
        }
    }
}

matrix fib(unsigned int n)
{
    matrix a;
    a.mat[0][0] = 1; a.mat[0][1] = 1;
    a.mat[1][0] = 1; a.mat[1][1] = 0;
    return power(a,n);
}

int main(void)
{
    matrix a;
    unsigned int num;
    printf("Enter the number: ");
    scanf("%u", &num);
    a = fib(num);
    printf("%u\n", a.mat[0][0]);
    return 0;
}