/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/bootstrap/boostrap_2016_sokoban/SRC
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 11 19:49:26 2016 
** Last update Mon Dec 12 13:13:41 2016 
*/

#include	<unistd.h>
#include	"my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
