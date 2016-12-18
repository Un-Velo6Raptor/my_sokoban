/*
** my_strcmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Dec 14 11:23:28 2016 
** Last update Wed Dec 14 11:23:29 2016 
*/

#include	"my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	idx;

  idx = 0;
  while (s1[idx] == s2[idx])
    {
      idx++;
      if (s1[idx] == '\0' && s2[idx] == '\0')
	return (0);
    }
  if (s1[idx] > s2[idx] && s1[idx] != '\0')
    return (1);
  else
    return (-1);
  return (0);
}
