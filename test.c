#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "bonus/so_long_bonus.h"
int main(int ac, char **av)
{
    // srand(atoi(av[1]));
    // for (int i = 0; i < 10; i++)
    // {
    //     int n = rand() % 5;
    //     printf("%d", n);
    //     if (i < 9)
    //         printf(":");
    // }
    // fill_animation_path(&i);
    void *d = mlx_init();
    void *w = mlx_new_window(d, 200, 200, "sd");
    int l = 64;
    void *im = mlx_xpm_file_to_image(d, "mandatory/assets/wall.xpm", &l, &l);
    mlx_destroy_image(d, im);
    mlx_destroy_window(d,w);
    int m;
    int i;
    fprintf(stderr,"%d\n%d\n", i, m);
    i = mlx_put_image_to_window(d, w, im, 200, 200);
    fprintf(stderr,"%d\n%d", i, m);
    // mlx_loop(d);
}