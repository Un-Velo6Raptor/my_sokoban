/*
** p_up.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 22:02:12 2016 
** Last update Sun Dec 18 05:14:01 2016 
*/

#include	"my.h"
#include	"sokoban.h"

int	p_up_next(t_coo *coo_map, char ***map)
{
  char	car_tmp;

  car_tmp = coo_map->pos;
  if (coo_map->save[coo_map->player_y - 1][coo_map->player_x] != 'X' &&
      coo_map->save[coo_map->player_y - 1][coo_map->player_x] != 'P')
    coo_map->pos = coo_map->save[coo_map->player_y - 1][coo_map->player_x];
  else
    coo_map->pos = ' ';
  (*map)[coo_map->player_y - 2][coo_map->player_x] = 'X';
  (*map)[coo_map->player_y - 1][coo_map->player_x] = 'P';
  (*map)[coo_map->player_y][coo_map->player_x] = car_tmp;
  coo_map->player_y--;
  my_putstr("\a");
  coo_map->nb_touch++;
  return (0);
}

int	p_up(t_coo *coo_map, char ***map)
{
  char	car_tmp;

  if (coo_map->player_y - 1 < 0 ||
      coo_map->player_x > my_strlen(coo_map->save[coo_map->player_y - 1]) ||
      (*map)[coo_map->player_y - 1][coo_map->player_x] == '#')
    return (0);
  if ((*map)[coo_map->player_y - 1][coo_map->player_x] == 'X')
    {
      if (coo_map->player_y - 2 <= 0 ||
	  coo_map->player_x > my_strlen(coo_map->save[coo_map->player_y - 2]) ||
	  (*map)[coo_map->player_y - 2][coo_map->player_x] == 'X' ||
          (*map)[coo_map->player_y - 2][coo_map->player_x] == '#')
	return (0);
      p_up_next(coo_map, map);
      return (0);
    }
  car_tmp = coo_map->pos;
  coo_map->pos = (*map)[coo_map->player_y - 1][coo_map->player_x];
  (*map)[coo_map->player_y - 1][coo_map->player_x] = 'P';
  (*map)[coo_map->player_y][coo_map->player_x] = car_tmp;
  coo_map->player_y--;
  coo_map->nb_touch++;
  my_putstr("\a");
  return (0);
}
