/*
** loading.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec 15 22:29:59 2016 
** Last update Sun Dec 18 05:31:31 2016 
*/

#include	<unistd.h>
#include	<ncurses.h>
#include	"my.h"

void		print_end(int check, int idx, int temps, int touch)
{
  if (check == 0)
    my_putstr("Vous avez gagné en ");
  else
    my_putstr("Vous avez perdu en ");
  my_put_nbr(temps);
  my_putstr(" secondes sur la map ");
  my_put_nbr(idx);
  my_putstr(" avec ");
  my_put_nbr(touch);
  my_putstr(" touches !\n");
}

void		loading_next(int idx, int idx2, int tmp)
{
  while (idx <= 10)
    {
      refresh();
      while (idx2 < tmp * idx)
	{
	  mvprintw((LINES / 2 - 1), idx2, "#");
	  idx2++;
	}
      usleep(500000);
      idx++;
    }
  refresh();
  while (idx2 < COLS)
    {
      mvprintw((LINES / 2 - 1), idx2, "#");
      idx2++;
    }
  refresh();
  usleep(500000);
}

void		loading(int nb)
{
  sfMusic	*music;
  int		idx;
  int		idx2;
  int		tmp;
  char		*tmp2;

  idx = 0;
  clear();
  music = start_music("music/loading.ogg");
  tmp2 = int_to_str(nb);
  mvprintw((LINES / 2 - 3), (COLS / 2) - 12, "Chargement de la map : ");
  mvprintw((LINES / 2 - 3), (COLS / 2) + 12, tmp2);
  while (idx < COLS)
    {
      mvprintw((LINES / 2 - 2), idx, "-");
      mvprintw((LINES / 2), idx, "-");
      idx++;
    }
  idx = 1;
  tmp = COLS / 10;
  idx2 = 0;
  loading_next(idx, idx2, tmp);
  sfMusic_destroy(music);
}
