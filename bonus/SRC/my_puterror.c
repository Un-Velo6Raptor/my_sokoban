/*
** my_puterror.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec 15 21:00:44 2016 
** Last update Thu Dec 15 21:01:31 2016 
*/

#include	<unistd.h>
#include	"my.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}
