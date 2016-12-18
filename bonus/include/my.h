/*
** y.h for  in /home/januar_m/delivery/PSU/bootstrap/boostrap_2016_sokoban/include
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec 11 19:51:44 2016 
** Last update Sun Dec 18 05:25:47 2016 
*/

#ifndef MY_H_
# define MY_H_

#include	<SFML/Audio.h>
#include	"sokoban.h"

sfMusic	*start_music(char *);
int	my_put_nbr(int);
void	print_end(int, int, int, int);
void	ini_all(int);
int	one_music(char *, int);
int	check_pos_mouse(int, int, t_coo *, char **);
int	recup_souris(int *, int *);
void	ini_souris();
int	my_strlen(char *);
void	my_putstr(char *);
void	free_tab(char **);
int	ini_struct(t_coo *, char **);
int	p_left(t_coo *, char ***);
int	p_right(t_coo *, char ***);
int	p_up(t_coo *, char ***);
int	p_down(t_coo *, char ***);
char	**recup_map(t_coo *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
void	ini_map(t_coo *, char **);
int	start_the_game(t_coo *, char **, int);
int	check_finish(t_coo *, char **);
int	check_block(t_coo *, char **);
int	check_map(char **);
int	my_strcmp(char *, char *);
int	disp_help();
int	my_puterror(char *);
char	*int_to_str(int);
void	loading(int);

#endif /* !MY_H_ */
