//
// Created by Illya MALTSEV on 2019-12-22.
//

#ifndef FDF_MAP_H
#define FDF_MAP_H

typedef struct  s_map
{
    int         x;
    int         y;
    int         **map;
}               t_map;

void    ft_print_map(t_map * map);
t_map * ft_read_map(char * file_name)

#endif //FDF_MAP_H
