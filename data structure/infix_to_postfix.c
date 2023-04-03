#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;

} stack;

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }

    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

char *post_fix(stack *sp, char *a)
{
    int j = 0;
    char *new = malloc(sizeof(char) * sizeof(strlen(a)));
    int i = 0;

    while (a[i] != '\0')
    {
        if (a[i] != '-' && a[i] != '+' && a[i] != '*' && a[i] != '/')
        {
            new[j] = a[i];
            j++;
            i++;
        }
        else
        {
            if (isEmpty(sp))
            {
                push(sp, a[i]);
                i++;
            }
            else
            {
                int p = i;
                do
                {
                    if ((a[i] == '*' || a[i] == '/') &&
                        (sp->arr[sp->top] == '-' || sp->arr[sp->top] == '+'))
                    {
                        push(sp, a[i]);
                        i++;
                    }
                    else if (!isEmpty(sp))
                    {
                        new[j] = pop(sp);
                        j++;
                    }
                    else
                    {
                        push(sp, a[i]);
                        i++;
                    }

                } while (p == i);
            }
        }
    }
    while (!isEmpty(sp))
    {
        new[j] = pop(sp);
        j++;
    }
    new[j] = '\0';
    return new;
}

int main()
{
    stack *sp = malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(char));

    char *a = "x-y/z-r*d";
    char *new = post_fix(sp, a);
    printf("%s\n", new);
    free(sp->arr);
    free(sp);
    free(new);
    return 0;
}
