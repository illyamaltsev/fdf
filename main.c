#include <stdio.h>
#include <fcntl.h>
#include "minilibx_macos/mlx.h"
#include "libft/mylibft.h"
#include "map.h"


#define WIDTH 720

#define HEIGHT 720
#include <math.h>

//static void	draw_line(t_point f, t_point s, t_fdf *fdf)
//{
//	t_point	delta;
//	t_point	sign;
//	t_point	cur;
//	int		error[2];
//
//	delta.x = FT_ABS(s.x - f.x);
//	delta.y = FT_ABS(s.y - f.y);
//	sign.x = f.x < s.x ? 1 : -1;
//	sign.y = f.y < s.y ? 1 : -1;
//	error[0] = delta.x - delta.y;
//	cur = f;
//	while (cur.x != s.x || cur.y != s.y)
//	{
//		put_pixel(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
//		if ((error[1] = error[0] * 2) > -delta.y)
//		{
//			error[0] -= delta.y;
//			cur.x += sign.x;
//		}
//		if (error[1] < delta.x)
//		{
//			error[0] += delta.x;
//			cur.y += sign.y;
//		}
//	}
//}
//
//void draw_line(int x0, int y0, int x1, int y1)
//{
//    int deltax = x1 - x0;
//    int deltay = y1 - y0;
//
//
//}

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void draw_square(void * connection, void * window, int x, int y, int z)
{
    int start_pix_x = 200;
    int start_pix_y = 200;

    int i = 0;
    while(i++ < x)
    {
        int x_tmp_1 = i;
        int x_tmp_2 = i;
        int y_tmp_1 = 0;
        int y_tmp_2 = y;

        iso(&x_tmp_1, &y_tmp_1, z);
        mlx_pixel_put(connection, window, start_pix_x+x_tmp_1, start_pix_y+y_tmp_1, 0xFFFFFF);
        iso(&x_tmp_2, &y_tmp_2, z);
        mlx_pixel_put(connection, window, start_pix_x+x_tmp_2, start_pix_y+y_tmp_2, 0xFFFFFF);
    }

    i = 0;
    while(i++ < y)
    {
        int x_tmp_1 = 0;
        int x_tmp_2 = x;
        int y_tmp_1 = i;
        int y_tmp_2 = i;

        iso(&x_tmp_1, &y_tmp_1, z);
        mlx_pixel_put(connection, window, start_pix_x+x_tmp_1, start_pix_y+y_tmp_1, 0xFFFFFF);
        iso(&x_tmp_2, &y_tmp_2, z);
        mlx_pixel_put(connection, window, start_pix_x+x_tmp_2, start_pix_y+y_tmp_2, 0xFFFFFF);
    }
}

void draw_points(void *connection, void *window, t_map *map)
{
    int start_pix_x = 400;
    int start_pix_y = 400;
    int diff = 20;

    int i = 0;
    while(i < map->x)
    {
        int j = 0;
        while (j < map->y)
        {
            int z = map->map[j][i] * diff;
            int x = i*diff;
            int y = j*diff;
            iso(&x, &y, z);
            mlx_pixel_put(connection, window, start_pix_x+x, start_pix_y+y, 0xFFFFFF);

            j++;
        }
        i++;
    }
}

void fdf_init(t_map * map)
{
    void * connection = mlx_init();
    void * window = mlx_new_window(connection, WIDTH, HEIGHT, "imaltsev");
    //void * img = mlx_new_image(connection, WIDTH, HEIGHT);


    mlx_string_put(connection, window, 0, 0 , 0xFFFFFF, "LOL");
    mlx_pixel_put(connection, window, 100, 100, 0xFFFFFF);


    draw_points(connection, window, map);
    //draw_square(connection, window, map->x*10, map->y*10, 0);
    //draw_square(connection, window, map->x*10, map->y*10, 100);
    mlx_loop(connection);
}

int main(int argc, char **argv) {

    if (argc != 2)
    {
        ft_printf("Error");
        return 0;
    }


    t_map * map = ft_read_map(argv[1]);

    ft_print_map(map);
    fdf_init(map);

    return 0;
}