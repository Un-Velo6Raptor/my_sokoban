/*
** check_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 13 18:48:53 2016 
** Last update Wed Dec 14 23:26:49 2016 
*/

#include	<stdio.h>
#include	"my.h"

int	count_all(char **map, int cpt_p, int cpt_x, int cpt_o)
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
	    cpt_x++;
	  else if (map[idx][idx2] == 'P')
	    cpt_p++;
	  else if (map[idx][idx2] == 'O')
	    cpt_o++;
	  else if (map[idx][idx2] != '#' && map[idx][idx2] != ' ' &&
		   map[idx][idx2] != '\n')
	    return (1);
	  idx2++;
	}
      idx++;
    }
  if (cpt_x != cpt_o || cpt_p != 1 || cpt_x == 0)
    return (1);
  return (0);
}

int	check_map(char **map)
{
  if (count_all(map, 0, 0, 0) == 1)
    return (1);
  return (0);
}
