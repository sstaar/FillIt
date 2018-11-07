/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:00:47 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/07 11:21:14 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"

typedef struct			s_tetris
{
	char				**tet;
	int					order;
	int					**coor;
	int					is_used;
	struct s_tetris		*next;
}						t_tetris;

t_tetris				*get_tetriminos(const int fd);
void					change_tets(t_tetris **tets);
int						**get_coor(t_tetris *lst);
char					**smallest_square(const int lenght);
int						get_nbr_tets(t_tetris *lst);
int						get_lenght(t_tetris *lst);
void					fill_square(t_tetris **original);
void					fill_coor(t_tetris **original);
void					display_square(char **square);
int						check_lists(t_tetris *lst);
int						check_lil_squ(t_tetris *original);
char					**back_square(int lenght, t_tetris **tets);
int						opti(t_tetris *tets, char **sqr);

#endif
