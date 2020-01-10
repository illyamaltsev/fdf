//
// Created by Illya MALTSEV on 2019-12-22.
//

#include <fcntl.h>
#include "map.h"
#include "libft/mylibft.h"


t_map * ft_get_map_x_y(const int fd, t_map *map)
{
    char * line;
    int count_x = 0;
    int count_y = 0;

    if (get_next_line(fd, &line))
    {
        count_y++;
        char ** str_arr = ft_strsplit(line, ' ');

        while (*str_arr++) count_x++;
        ft_strdel(&line);
    }

    while (get_next_line(fd, &line))
    {
        count_y++;
        ft_strdel(&line);
    }

    map->x = count_x;
    map->y = count_y;
    return map;
}

t_map * ft_read_map(char * file_name)
{
    char ** split_arr;
    char *  line;
    int     i;
    int     j;

    int fd = open(file_name, O_RDWR);

    t_map *map = (t_map *)malloc(sizeof(t_map));

    ft_get_map_x_y(fd, map);
    close(fd);

    printf("x = %d, y = %d\n", map->x, map->y);

    fd = open(filename, O_RDWR);


    map->map = (int **)malloc(map->y * (sizeof(int*) + 1));
    i = 0;
    while (get_next_line(fd, &line))
    {
        map->map[i] = (int*)malloc(map->x * (sizeof(int)));
        split_arr = ft_strsplit(line, ' ');
        j = 0;
        while (j < map->x) {
            char * str = split_arr[j];
            int ret = ft_atoi(str);
            map->map[i][j] = ret;
            j++;
        }
        ft_strdel(&line);
        i++;
    }
    map->map[i] = NULL;
    return map;
}



void ft_print_map(t_map * map)
{
    int i = 0;
    while(i < map->y)
    {
        int j = 0;
        while (j < map->x)
        {
            ft_printf("%d ", map->map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}
