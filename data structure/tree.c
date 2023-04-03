#include <stdio.h>
#include <stdlib.h>

// tree data structure
typedef struct node
{
    int num;
    struct node *left;
    struct node *right;

} node;

int assign(node *list, int new_num);
void print_node(node *list);
void free_node(node *list);

int main(void)
{
    // list of array
    node *list = NULL;

    // assigning data
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        return 1;
    }

    temp->num = 2;
    temp->left = NULL;
    temp->right = NULL;

    list = temp;

    assign(list, 3);
    assign(list, 4);
    assign(list, 5);
    assign(list, 7);
    assign(list, 6);
    assign(list, 12);
    assign(list, 13);

    // index(list, 13);

    print_node(list);
    free_node(list);
    return 0;
}

// printing function
void print_node(node *list)
{

    if (list != NULL)
    {
        print_node(list->left);
        printf("%d\n", list->num);
        print_node(list->right);
    }
}

// freeing function
void free_node(node *list)
{
    if (list != NULL)
    {
        free_node(list->left);
        free_node(list->right);
        free(list);
    }
}

// assigning data to list
int assign(node *list, int new_num)
{
    node *temp = malloc(sizeof(node));
    node *p = list;
    node *q = p;
    if (temp == NULL)
    {
        return 1;
    }

    temp->num = new_num;
    temp->left = NULL;
    temp->right = NULL;

    while (p != NULL)
    {
        q = p;
        if (p->num >= new_num)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }

    if (q->num >= new_num)
    {
        q->right = temp;
    }
    else
    {
        q->left = temp;
    }
    return 0;
}
