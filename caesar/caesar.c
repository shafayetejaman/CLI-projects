#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
   //geting the key:
     if (argc != 2)
     {
         printf("Usage: ./caesar key");
         return 1;
     }

     for (int i = 0; i < strlen(argv[1]); i++)
     {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
     }

     int k = atoi(argv[1]);

    //geting the ciphertext:
     string text = get_string("plaintext: ");
     //printing the ciphertext:
     printf("ciphertext: ");

     for (int i = 0; i < strlen(text); i++)
     {
        if (isalpha(text[i]))
        {
           if (islower(text[i]))
           {
               printf("%c", (((text[i] - 97) + k) % 26) + 97);
           }
           if (isupper(text[i]))
           {
               printf("%c", (((text[i] - 65) + k) % 26) + 65);
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