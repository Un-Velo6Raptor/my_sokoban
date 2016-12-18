/*
** my_put_nbr.c for  in /home/januar_m/delivery/CPool_Day03
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Wed Oct  5 16:44:31 2016 Martin Januario
** Last update Sun Dec 18 04:15:50 2016 
*/

#include	<unistd.h>
#include	"my.h"

void		my_putchar(char f)
{
  write(1, &f, 1);
}

int		my_put_nbr(int nb)
{
  int		idx;
  long int	nb1;

  nb1 = nb;
  idx = 1;
  if (nb1 < 0)
    {
      my_putchar('-');
      nb1 = nb1 * -1;
    }
  while ((nb1 / idx) >= 10)
    idx = idx * 10;
  while (idx > 0)
    {
      my_putchar((nb1 / idx) % 10 + 48);
      idx = idx / 10;
    }
  return (0);
}
