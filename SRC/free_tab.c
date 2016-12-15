/*
** free_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 16:24:13 2016 
** Last update Mon Dec 12 16:55:33 2016 
*/

#include	<stdlib.h>
#include	"my.h"

void	free_tab(char **tab)
{
  int	idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      free(tab[idx]);
      idx++;
    }
  free(tab);
}
