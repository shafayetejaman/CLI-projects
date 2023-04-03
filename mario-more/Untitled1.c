
// program for generating random password
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// random number generator between min to max
int ran(int max, int min);

int main(void)
{
    int len;

    // getting the password length from the user
    do
    {
        printf("password length : ");
        if (scanf("%d", &len) != 1)
        {
            printf("INVALID INPUT!\n");
            return 1;
        }
    }
    while (len < 0);

    char pass[len + 1];
    int max = 126;
    int min = 33;

    printf("Generating The Password.");

    // generating the password
    int i = 0;
    while (len > 0)
    {
        pass[i] = (char)ran(max, min);
        i++;
        len--;
        printf(".");
    }
    pass[i] = '\0';

    printf("\nyour password is : %s\n", pass);

    return 0;
}

// random number generator between min to max
int ran(int max, int min)
{
    srand(time(NULL) * getpid());
    return (rand() % (max - min + 1)) + min;
}
