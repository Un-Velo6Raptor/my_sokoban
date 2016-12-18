/*
** int_to_str.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 18 06:20:15 2016 
** Last update Sun Dec 18 06:20:23 2016 
*/

#include	<stdlib.h>
#include	"my.h"

int	cpt_long(int idx, int nb1, int *idx2)
{
  while ((nb1 / idx) >= 10)
    {
      idx = idx * 10;
      (*idx2)++;
    }
  return (idx);
}

int		malloc_this(char **res, int idx2, int nb)
{
  if (nb >= 0)
    {
      nb = 0;
      if ((*res = malloc(idx2 + 2)) == NULL)
	return (-84);
    }
  else
    {
      nb = 1;
      if ((*res = malloc(idx2 + 3)) == NULL)
	return (-84);
      *res[0] = '-';
    }
  return (nb);
}

char		*int_to_str(int nb)
{
  int		idx;
  long int	nb1;
  int		idx2;
  char		*res;

  nb1 = nb;
  idx = 1;
  idx2 = 0;
  if (nb1 < 0)
    nb1 = nb1 * -1;
  idx = cpt_long(idx, nb1, &idx2);
  if ((nb = malloc_this(&res, idx2, nb)) == -84)
    return (NULL);
  while (idx > 0)
    {
      res[nb] = (nb1 / idx) % 10 + 48;
      idx = idx / 10;
      nb++;
    }
  res[nb] = '\0';
  return (res);
}
