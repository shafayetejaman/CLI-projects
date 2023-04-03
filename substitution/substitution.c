#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //validating the key :
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        for (int j = (i + 1), x = strlen(argv[1]); j < x; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");

    //printing the ciphertext:
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                printf("%c", (toupper(argv[1][(text[i] - 97)])) + 32);
            }
            if (isupper(text[i]))
            {
                printf("%c", (toupper(argv[1][(text[i] - 65)])));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}