/*
** sokoban.h for  in /home/januar_m/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec 12 16:56:59 2016 
** Last update Sun Dec 18 04:26:01 2016 
*/

#ifndef SOKOBAN_H_
# define SOKOBAN_H_

typedef struct	s_coo
{
  int	player_x;
  int	player_y;
  int	mouse_x;
  int	mouse_y;
  char	pos;
  char	pos_X;
  char	**save;
  int	lenght;
  int	nb_ligne;
  int	nb_touch;
} t_coo;

#endif /* !SOKOBAN_H_ */
