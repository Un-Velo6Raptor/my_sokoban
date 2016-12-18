/*
** main.c for  in /home/januar_m/delivery/PSU/bootstrap/boostrap_2016_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 11 19:31:01 2016 
** Last update Sun Dec 18 17:10:20 2016 
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	"my.h"
#include	"sokoban.h"

int		count_line(char *str)
{
  int		idx;
  int		res;

  idx = 0;
  res = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] == '\n')
	res++;
      idx++;
    }
  return (res);
}

int		nb_ligne(char *str)
{
  char		buffer[1024];
  int		fd;
  int		size;
  int		nb;

  nb = 0;
  if ((fd = open(str, O_RDONLY)) == -1)
    return (-1);
  while ((size = read(fd, buffer, 1023)) > 0)
    {
      buffer[size] = '\0';
      nb += count_line(buffer);
    }
  if (close(fd) == -1)
    return (-1);
  return (nb);
}

char		**make_tab(char *str, t_coo *coo_map)
{
  FILE		*stream;
  size_t	len;
  ssize_t	read;
  char		**tmp;
  int		idx;

  idx = nb_ligne(str);
  len = 0;
  tmp = NULL;
  if (idx <= 0 || (tmp = malloc(sizeof(char *) * (idx + 2))) == NULL ||
      (coo_map->save = malloc(sizeof(char *) * (idx + 2))) == NULL)
    return (NULL);
  if ((stream = fopen(str, "r")) == NULL)
    return (NULL);
  idx = 0;
  tmp[idx] = NULL;
  while ((read = getline(&tmp[idx], &len, stream)) > 0)
    {
      tmp[idx][read] = '\0';
      tmp[++idx] = NULL;
    }
  tmp[idx] = NULL;
  if (fclose(stream) == -1)
    return (NULL);
  return (tmp);
}

int		main(int argc, char **argv)
{
  char		**map;
  t_coo		*coo_map;

  map = NULL;
  if (argc != 2)
    return (84);
  if (my_strcmp(argv[1], "-h") == 0)
    return (disp_help());
  if ((coo_map = malloc(sizeof(t_coo) * 1)) == NULL)
    return (84);
  if ((map = make_tab(argv[1], coo_map)) == NULL)
    return (84);
  if (check_map(map) == 1)
    return (84);
  ini_map(coo_map, map);
  ini_struct(coo_map, map);
  if (coo_map->nb_ligne < 2 || coo_map->lenght < 2)
    return (84);
  return (start_the_game(coo_map, map));
}
