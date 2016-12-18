/*
** p_left.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 21:32:21 2016 
** Last update Sun Dec 18 05:20:38 2016 
*/

#include	"my.h"
#include	"sokoban.h"

int	p_left_next(t_coo *coo_map, char ***map)
{
  char	car_tmp;

  car_tmp = coo_map->pos;
  if ((*map)[coo_map->player_y][coo_map->player_x - 2] == '#' ||
      (*map)[coo_map->player_y][coo_map->player_x - 2] == '\n' ||
      (*map)[coo_map->player_y][coo_map->player_x - 2] == '\0')
    return (0);
  if (coo_map->save[coo_map->player_y][coo_map->player_x - 1] != 'X' &&
      coo_map->save[coo_map->player_y][coo_map->player_x - 1] != 'P')
    coo_map->pos = coo_map->save[coo_map->player_y][coo_map->player_x - 1];
  else
    coo_map->pos = ' ';
  (*map)[coo_map->player_y][coo_map->player_x - 2] = 'X';
  (*map)[coo_map->player_y][coo_map->player_x - 1] = 'P';
  (*map)[coo_map->player_y][coo_map->player_x] = car_tmp;
  coo_map->player_x--;
  coo_map->nb_touch++;
  my_putstr("\a");
  return (0);
}

int	p_left(t_coo *coo_map, char ***map)
{
  char	car_tmp;

  if (coo_map->player_x - 1 < 0 ||
      (*map)[coo_map->player_y][coo_map->player_x - 1] == '#' ||
      (*map)[coo_map->player_y][coo_map->player_x - 1] == '\n' ||
      (*map)[coo_map->player_y][coo_map->player_x - 1] == '\0')
    return (0);
  if ((*map)[coo_map->player_y][coo_map->player_x - 1] == 'X')
    {
      if (coo_map->player_x - 2 < 0 ||
	  (*map)[coo_map->player_y][coo_map->player_x - 2] == 'X' ||
	  (*map)[coo_map->player_y][coo_map->player_x - 2] == '#')
	return (0);
      p_left_next(coo_map, map);
      return (0);
    }
  car_tmp = coo_map->pos;
  coo_map->pos = (*map)[coo_map->player_y][coo_map->player_x - 1];
  (*map)[coo_map->player_y][coo_map->player_x - 1] = 'P';
  (*map)[coo_map->player_y][coo_map->player_x] = car_tmp;
  coo_map->player_x--;
  coo_map->nb_touch++;
  my_putstr("\a");
  return (0);
}
