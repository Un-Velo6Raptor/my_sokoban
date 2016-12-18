/*
** display_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 18 14:38:27 2016 
** Last update Sun Dec 18 15:32:57 2016 
*/

#include	<ncurses.h>
#include	"my.h"
#include	"sokoban.h"

void	display_1(int idx, int idx2, t_coo *coo_map)
{
  attron(COLOR_PAIR(1));
  mvaddch((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
	  (COLS / 2) - (coo_map->lenght / 2) + idx2, '#');
  attroff(COLOR_PAIR(1));
}

void	display_2(int idx, int idx2, t_coo *coo_map)
{
  attron(COLOR_PAIR(2) | A_BOLD);
  mvaddch((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
	   (COLS / 2) - (coo_map->lenght / 2) + idx2, 'P');
  attroff(COLOR_PAIR(2) | A_NORMAL);
}

void	display_3(int idx, int idx2, t_coo *coo_map)
{
  attron(COLOR_PAIR(4) | A_BOLD);
  mvaddch((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
	   (COLS / 2) - (coo_map->lenght / 2) + idx2, 'O');
  attroff(COLOR_PAIR(4) | A_NORMAL);
}

void	display_4(int idx, int idx2, t_coo *coo_map)
{
  attron(COLOR_PAIR(6) | A_BOLD);
  mvaddch((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
	   (COLS / 2) - (coo_map->lenght / 2) + idx2, 'X');
  attroff(COLOR_PAIR(6) | A_NORMAL);
}

void	display_map(char **map, t_coo *coo_map)
{
  int	idx;
  int	idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == '#')
	    display_1(idx, idx2, coo_map);
	  else if (map[idx][idx2] == 'P')
	    display_2(idx, idx2, coo_map);
	  else if (map[idx][idx2] == 'O')
	    display_3(idx, idx2, coo_map);
	  else if (map[idx][idx2] == 'X')
	    display_4(idx, idx2, coo_map);
	  else
	    mvaddch((LINES / 2 + idx) - (coo_map->nb_ligne / 2),
                     (COLS / 2) - (coo_map->lenght / 2) + idx2,
		    map[idx][idx2]);
	  idx2++;
	}
      idx++;
    }
}
