#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0, e_size = 0, count = 0;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    do
    {
        e_size = get_int("End size: ");
    }
    while (n > e_size);

    while(n < e_size)
    {
        n = n + (n / 3) - (n / 4);
        count++;
    }

    printf("Years: %i\n", count);
    return 0;

}