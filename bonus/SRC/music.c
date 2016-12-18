/*
** music.c for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Dec 17 18:42:09 2016 
** Last update Sun Dec 18 05:26:13 2016 
*/

#include	<SFML/Audio.h>
#include	<unistd.h>
#include	"my.h"

sfMusic		*start_music(char *str)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  return (music);
}

int		one_music(char *str, int idx)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  sfMusic_play(music);
  if (idx == 1)
    usleep(7500000);
  else
    usleep(4500000);
  sfMusic_destroy(music);
  return (0);
}
