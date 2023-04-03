#include <stdio.h>
#include <stdlib.h>

// making structure
typedef struct node
{
    int num;
    struct node *next;
}
node;

int main(void)
{
    // list of array
    node *list = NULL;

    // temp variable to store number
    node *temp = malloc(sizeof(node));
    if(temp == NULL)
    {
        return 1;
    }

    temp->num = 1;
    temp->next = NULL;

    // update list
    list = temp;

    // new temp variable to store number
    temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    temp->num = 2;
    temp->next = NULL;

    // update list for next num
    list->next = temp;

 // new temp variable to store number
    temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    temp->num = 3;
    temp->next = NULL;

    // update list for next num
    list->next->next = temp;

    // print list
    for (node *n = list; n != NULL; n = n->next)
    {
        printf("%d\n", n->num);
    }

    //free list
    while (list != NULL)
    {
        node *n = list->next;
        free(list);
        list = n;
    }
    return 0;
}