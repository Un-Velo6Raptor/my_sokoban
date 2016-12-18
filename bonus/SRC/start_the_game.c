/*
** start_the_game.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 17:40:37 2016 
** Last update Sun Dec 18 05:37:55 2016 
*/

#include	<SFML/Audio.h>
#include	<ncurses.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	"my.h"
#include	"sokoban.h"

int		gest_key(t_coo *coo_map, char **map, int tmp)
{
  int		mouse_x;
  int		mouse_y;

  if (recup_souris(&mouse_x, &mouse_y) == OK)
    check_pos_mouse(mouse_x, mouse_y, coo_map, map);
  else if (tmp == KEY_LEFT)
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
      if (check_block(coo_map, map) == 1)
	return (1);
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

int		start_the_game(t_coo *coo_map, char **map, int idx)
{
  WINDOW	*window;
  sfMusic	*music;
  int		tmp;
  int		tmp_time;

  window = initscr();
  ini_all(idx);
  music = start_music("music/sound.ogg");
  tmp_time = time(NULL);
  while ((tmp = start_the_loop(coo_map, map, 0, 0)) != 0 && tmp != 1)
    {
      sfMusic_stop(music);
      loading(idx);
      free_tab(map);
      map = recup_map(coo_map);
      if (map == NULL)
	return (84);
      ini_struct(coo_map, map);
      music = start_music("music/sound.ogg");
    }
  endwin();
  sfMusic_destroy(music);
  print_end(tmp, idx, time(NULL) - tmp_time, coo_map->nb_touch);
  return (tmp);
}
