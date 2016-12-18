/*
** recup_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 23:02:39 2016 
** Last update Wed Dec 14 09:53:34 2016 
*/

#include	<stdlib.h>
#include	"my.h"
#include	"sokoban.h"

int	ct_line(char **tab)
{
  int	idx;

  idx = 0;
  while (tab[idx] != NULL)
    idx++;
  return (idx);
}

char	**recup_map(t_coo *coo_map)
{
  char	**tmp;
  int	idx;

  idx = 0;
  if ((tmp = malloc(sizeof(char *) * (ct_line(coo_map->save) + 1))) == NULL)
    return (NULL);
  while (coo_map->save[idx] != NULL)
    {
      tmp[idx] = my_strdup(coo_map->save[idx]);
      idx++;
    }
  tmp[idx] = NULL;
  return (tmp);
}
