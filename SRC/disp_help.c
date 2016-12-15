/*
** disp_help.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Dec 14 11:23:40 2016 
** Last update Wed Dec 14 11:49:54 2016 
*/

#include	"my.h"

int	disp_help()
{
  my_putstr("USAGE\n");
  my_putstr("\t   ./my_sokoban map\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\t   map\tfile representing the warehouse map, ");
  my_putstr("containing '#' for walls,\n\t\t'P' for the player,");
  my_putstr(" 'X' for boxes and 'O' for storage locations\n");
  return (0);
}
