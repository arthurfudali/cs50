// prints a pyramid based on a height prompt

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// declares a funcion
void print_row(int spaces, int height);

// main funcion
int main(void)
{
    int x = 0;
    do
    {
        x = get_int("Height: ");
    }
    while (x <= 0);

    for (int i = 1; i <= x; i++)
    {
        print_row(i, x);
    }
}

// print row function
void print_row(int size, int height)
{
    for (int a = 0; a < height - size; a++)
    {
        printf(" ");
    }
    for (int i = 0; i < size; i++)
    {
        printf("#");
    }
    printf("\n");
}
