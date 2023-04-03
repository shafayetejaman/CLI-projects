#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function for replacing word
char *replace(char old_str[], char old_word[], char new_word[]);

int main(void)
{
    char str[100000];
    char old_word[1000];
    char new_word[1000];

    printf("give the text : ");
    scanf("%[^\n]%*c", str);

    printf("type the word you want to replace : ");
    scanf("%[^\n]%*c", old_word);

    printf("type the word you want to replace to : ");
    scanf("%[^\n]%*c", new_word);

    char *result = replace(str, old_word, new_word);
    printf("%s\n", result);

    free(result);

    return 0;
}

// function for replacing word
char *replace(char old_str[], char old_word[], char new_word[])
{
    // calculating the length of the string
    int old_str_len = strlen(old_str);
    int old_word_len = strlen(old_word);
    int new_word_len = strlen(new_word);

    // allocating memory for the new string
    char *new_str = NULL;

    if (old_word_len == new_word_len)
    {
        new_str = malloc((old_str_len + 1) * sizeof(char));
    }
    else
    {
        int occurrence = 0;
        int i = 0;

        // checking the occurrence of the old word
        while (i < old_str_len)
        {
            if (strstr(&old_str[i], old_word) == &old_str[i])
            {
                occurrence++;
                i += old_word_len;
            }
            else
            {
                i++;
            }
        }

        // calculating the difference of length for the new string
        int len = old_str_len + (new_word_len - old_word_len);

        new_str = malloc((len + 1) * sizeof(char));
    }

    int i = 0;
    int j = 0;

    // replacing the old word with the new word
    while (i < old_str_len)
    {
        if (strstr(&old_str[i], old_word) == &old_str[i])
        {
            strcpy(&new_str[j], new_word);
            j += new_word_len;
            i += old_word_len;
        }
        else
        {
            new_str[j] = old_str[i];
            i++;
            j++;
        }
    }

    new_str[j] = '\0';

    return new_str;
}

