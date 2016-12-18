/*
** ini_struct.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 17:19:09 2016 
** Last update Sun Dec 18 04:25:33 2016 
*/

#include	<stdlib.h>
#include	"my.h"
#include	"sokoban.h"

int	ini_taille(t_coo *coo_map, char **map)
{
  int	idx;
  int	idx2;

  idx = 0;
  coo_map->lenght = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0' && map[idx][idx2] != '\n')
	idx2++;
      if (coo_map->lenght < idx2)
	coo_map->lenght = idx2;
      idx++;
    }
  coo_map->nb_ligne = idx;
  return (0);
}

int	ini_struct(t_coo *coo_map, char **map)
{
  int	idx;
  int	idx2;

  idx = 0;
  coo_map->pos = ' ';
  coo_map->pos_X = ' ';
  coo_map->nb_touch = 0;
  ini_taille(coo_map, map);
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == 'P')
	    {
	      coo_map->player_x = idx2;
	      coo_map->player_y = idx;
	      return (0);
	    }
	  idx2++;
	}
      idx++;
    }
  return (0);
}
