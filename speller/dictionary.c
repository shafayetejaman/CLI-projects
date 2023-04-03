// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 2;

// Hash table
node *table[N];

long long int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hash_val = hash(word);
    node *c = table[hash_val];

    while (c != NULL)
    {
        if (strcasecmp(word, c->word) == 0)
        {
            return true;
        }
        else
        {
            c = c->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long long int sum = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += toupper(word[i]);
    }

    if (toupper(word[1]) == 'A')
    {
        return (sum % 26) + 26;
    }
    else
    {
        return sum % 26;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, buffer);
        long long int hash_val = hash(buffer);
        n->next = table[hash_val];
        table[hash_val] = n;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int i = 0;

    while (i < N)
    {
        node *c = table[i];
        while (c != NULL)
        {
            node *temp = c;
            c = c->next;
            free(temp);
        }
        i++;

        if (c == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
