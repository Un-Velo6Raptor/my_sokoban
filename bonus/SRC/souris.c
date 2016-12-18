/*
** souris.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Dec 16 12:33:11 2016 
** Last update Sun Dec 18 03:46:30 2016 
*/

#include	<stdlib.h>
#include	<ncurses.h>
#include	"my.h"
#include	"sokoban.h"

int		check_pos_mouse(int x, int y, t_coo *coo_map, char **map)
{
  if (y <= LINES / 2)
    {
      if (x < COLS / 2)
	p_down(coo_map, &map);
      else
	p_up(coo_map, &map);
    }
  else
    {
      if (x < COLS / 2)
	p_left(coo_map, &map);
      else
	p_right(coo_map, &map);
    }
  return (0);
}

int		recup_souris(int *x, int *y)
{
  MEVENT	event;
  int		res;
  int		bouton;

  res = getmouse(&event);
  if (res == OK)
    {
      *x = event.x;
      *y = event.y;
      bouton = event.bstate;
    }
  if (bouton != BUTTON1_CLICKED)
    return (-1);
  return (res);
}

void	ini_souris()
{
  if (mousemask(ALL_MOUSE_EVENTS, NULL) == 0)
    {
      endwin();
      exit(84);
    }
  if (has_mouse() == FALSE)
    {
      endwin();
      exit(84);
    }
}

void		ini_all(int idx)
{
  curs_set(FALSE);
  noecho();
  keypad(stdscr, TRUE);
  scrollok(stdscr, TRUE);
  loading(idx);
  ini_souris();
}
