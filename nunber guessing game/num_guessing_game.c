#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// random number generator between min to max
int computer(int max, int min)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main(void)
{
    int max;
    // getting user input of the maximum number
    printf("Enter the max number : ");
    if (scanf("%d", &max) != 1)
    {
        printf("Invalid Input!\n");
        return 1;
    }


    // user tarn to guess
    int n = -1;
    // computer's number
    int c = computer(max, 0);
    int u_score = -1;

    while (n != c)
    {
        do
        {
            // checking the guessed number difference
            if (n != -1 && n > c)
            {
                printf("the number is smaller\n");
            }
            else if (n != -1 && n < c)
            {
                printf("the number is larger\n");
            }

            printf("Guess the number : ");
            scanf("%d", &n);

            // keeping trac of the score of the user
            u_score++;

        } while (max < n || n < 0);
    }

    printf("the computers number was : %d\nyour attempt was : %d\n", c, u_score);

    // computer's turn to guess
    // getting the user number for the computer to guess
    do
    {
        printf("it's computers turn\nenter your number : ");
        if (scanf("%d", &n) != 1)
        {
            printf("Invalid Input!\n");
            return 1;
        }

    } while (max < n || n < 0);

    c = -1;
    int c_score = 0;
    int min = 0;
    int t;

    while (1)
    {
        c = computer(max, min);

        // modifing the computers number
        if (t == c && max > c && n != c)
        {
            c++;
        }
        else if (t == c && max == c && n != c)
        {
            c--;
        }

        if (n == c)
        {
            break;
        }

        // keeping trac of the score of the computer
        c_score++;

        printf("the computer guessed : %d\n", c);

        int d;
        // getting the input from the user for if the the number is larger or smaller
        do
        {
            printf("tell the computer if the number is (0)smaller or (1)larger\n");
            if (scanf("%d", &d) != 1)
            {
                printf("Invalid Input!\n");
                return 1;
            }

        } while (d < 0 || d > 1);

        // readjusting the max and minimum number for the computer
        if (d == 0)
        {
            max = c - 1;
        }
        else
        {
            min = c + 1;
        }
        t = c;
    }

    // declaring the winier
    if (c_score > u_score)
    {
        printf("You won the game!\nyour score : %d\ncomputer's score : %d\n", u_score, c_score);
    }
    else if (c_score < u_score)
    {
        printf("computer won the game!\nyour score : %d\ncomputer's score : %d\n", u_score, c_score);
    }
    else
    {
        printf("It's a tie!\nyour score : %d\ncomputer's score : %d\n", u_score, c_score);
    }

    return 0;
}