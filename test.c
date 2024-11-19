#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Error: Failed to initialize MiniLibX.\n");
        return (1);
    }

    win = mlx_new_window(mlx, 800, 600, "Test");
    if (!win)
    {
        printf("Error: Failed to create window.\n");
        return (1);
    }

    img = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &img_width, &img_height);
    if (!img)
    {
        printf("Error: Failed to load image 'assets/wall.xpm'.\n");
        return (1);
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return (0);
}
