/*
** check_finish.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Dec 13 15:00:40 2016 
** Last update Sun Dec 18 06:12:25 2016 
*/

#include	<stdlib.h>
#include	"my.h"
#include	"sokoban.h"

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
