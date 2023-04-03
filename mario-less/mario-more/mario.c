#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int n;
    do
    {
        n = get_int("Height : ");
    }
    while(n < 1 || n > 8);

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
          printf(" ");
        }
        for(int x = 1; x <= i; x++)
        {
          printf("#");
        }
        for(int j = 1; j <= 2; j++)
        {
          printf(" ");
        }
        for(int x = 1; x <= i; x++)
        {
          printf("#");
        }
        printf("\n");
    }
    return 0;

}