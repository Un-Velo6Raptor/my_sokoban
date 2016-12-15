/*
** ini_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 22:50:35 2016 
** Last update Mon Dec 12 22:54:34 2016 
*/

#include	<stdlib.h>
#include	"my.h"
#include	"sokoban.h"

void	ini_map(t_coo *coo_map, char **map)
{
  int	idx;

  idx = 0;
  while (map[idx] != NULL)
    {
      coo_map->save[idx] = my_strdup(map[idx]);
      idx++;
    }
  coo_map->save[idx] = NULL;
}
