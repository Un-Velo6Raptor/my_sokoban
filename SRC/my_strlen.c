/*
** my_strlen.c for  in /home/januar_m/delivery/PSU/bootstrap/boostrap_2016_sokoban/SRC
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 11 19:48:04 2016 
** Last update Sun Dec 11 19:48:50 2016 
*/

#include	"my.h"

int	my_strlen(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
