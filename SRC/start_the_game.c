/*
** start_the_game.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 17:40:37 2016 
** Last update Sun Dec 18 15:35:05 2016 
*/

#include	<ncurses.h>
#include	"my.h"
#include	"sokoban.h"

int		gest_key(t_coo *coo_map, char **map, int tmp)
{
  if (tmp == KEY_LEFT)
    p_left(coo_map, &map);
  else if (tmp == KEY_RIGHT)
    p_right(coo_map, &map);
  else if (tmp == KEY_UP)
    p_up(coo_map, &map);
  else if (tmp == KEY_DOWN)
    p_down(coo_map, &map);
  else if (tmp == ' ')
    return (-1);
  return (0);
}

int		disp_error_next(int idx, int *tmp)
{
  while (idx > COLS)
    {
      if (idx % 2 == 0)
	idx = idx / 2;
      else
	idx = (idx + 1) / 2;
      (*tmp)++;
    }
  return (idx);
}

void		disp_error(int tmp, int idc, int cpt, int cpt_tmp)
{
  int		idx;

  idx = disp_error_next(6, &tmp);
  while (cpt < 6)
    {
      if (cpt == 5)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "E");
      if (cpt == 4)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "Z");
      if (cpt == 3)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "I");
      if (cpt == 2)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "S");
      if (cpt == 1)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "E");
      if (cpt == 0)
	mvprintw((LINES / 2) - tmp + cpt_tmp, (COLS / 2) - (idx / 2) + idc, "R");
      cpt++;
      idc++;
      if (idc == idx)
	{
	  cpt_tmp++;
	  idc = 0;
	}
    }
}

int		start_the_loop(t_coo *coo_map, char **map, int tmp, int idx)
{
  while (42)
    {
      idx = 0;
      clear();
      if (check_finish(coo_map, map) == 0)
	return (0);
      if (coo_map->lenght <= COLS && coo_map->nb_ligne <= LINES)
	while (map[idx] != NULL)
	  {
	    mvprintw((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
		     (COLS / 2) - (coo_map->lenght / 2), map[idx]);
	    idx++;
	  }
      else
	disp_error(0, 0, 0, 0);
      refresh();
      if ((tmp = getch()) != 410)
	tmp = gest_key(coo_map, map, tmp);
      if (tmp == -1)
	return (2);
    }
  return (0);
}

int		start_the_game(t_coo *coo_map, char **map)
{
  WINDOW	*window;
  int		tmp;

  window = initscr();
  curs_set(FALSE);
  noecho();
  keypad(stdscr, TRUE);
  while ((tmp = start_the_loop(coo_map, map, 0, 0)) != 0 && tmp != 1)
    {
      free_tab(map);
      map = recup_map(coo_map);
      if (map == NULL)
	return (84);
      ini_struct(coo_map, map);
    }
  endwin();
  return (tmp);
}
