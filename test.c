#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "bonus/so_long_bonus.h"
int main(int ac, char **av)
{
    srand(atoi(av[1]));
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 5;
        printf("%d", n);
        if (i < 9)
            printf(":");
    }
    // fill_animation_path(&i);
    printf("\ntest");
}