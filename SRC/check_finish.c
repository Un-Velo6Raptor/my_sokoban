/*
** check_finish.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 13 15:00:40 2016 
** Last update Tue Dec 13 18:04:15 2016 
*/

#include	<stdlib.h>
#include	"my.h"
#include	"sokoban.h"

int	check_pos_x(char **map, int y, int x, char **save)
{
  if ((map[y][x + 1] == 'X' || map[y][x + 1] == '#') &&
      (map[y + 1][x] == 'X' || map[y + 1][x] == '#'))
    return (0);
  if ((map[y + 1][x] == 'X' || map[y + 1][x] == '#') &&
      (map[y][x - 1] == 'X' || map[y][x - 1] == '#'))
    return (0);
  if ((map[y][x - 1] == 'X' || map[y][x - 1] == '#') &&
      (map[y - 1][x] == 'X' || map[y - 1][x] == '#'))
    return (0);
  if ((map[y][x + 1] == 'X' || map[y][x + 1] == '#') &&
      (map[y - 1][x] == 'X' || map[y - 1][x] == '#'))
    return (0);
  return (1);
}

int	check_block(t_coo *coo_map, char **map)
{
  int	idx;
  int	idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == 'X')
	    if (check_pos_x(map, idx, idx2, coo_map->save) == 1)
	      return (0);
	  idx2++;
	}
      idx++;
    }
  return (1);
}

int	check_finish(t_coo *coo_map, char **map)
{
  int	idx;
  int	idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (coo_map->save[idx][idx2] == 'O')
	    {
	      if (map[idx][idx2] != 'X')
		return (1);
	    }
	  idx2++;
	}
      idx++;
    }
  return (0);
}
