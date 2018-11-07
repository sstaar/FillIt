/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:56:22 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/06 17:55:53 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_if_poss(int **coor, const int x, const int y, char **square)
{
	int		width;

	width = ft_strlen(square[0]);
	if (x + coor[1][0] >= width || x + coor[1][0] < 0 ||
			x + coor[1][1] >= width || x + coor[1][1] < 0 ||
			x + coor[1][2] >= width || x + coor[1][2] < 0 ||
			x + coor[1][3] >= width || x + coor[1][3] < 0 ||
			y + coor[0][0] >= width || y + coor[0][0] < 0 ||
			y + coor[0][1] >= width || y + coor[0][1] < 0 ||
			y + coor[0][2] >= width || y + coor[0][2] < 0 ||
			y + coor[0][3] >= width || y + coor[0][3] < 0)
		return (0);
	else if (square[x + coor[1][0]][y + coor[0][0]] == '.' &&
			square[x + coor[1][1]][y + coor[0][1]] == '.' &&
			square[x + coor[1][2]][y + coor[0][2]] == '.' &&
			square[x + coor[1][3]][y + coor[0][3]] == '.')
		return (1);
	else
		return (0);
}

void		fill_tet(char ***square, t_tetris **tet, const int x, const int y)
{
	(*tet)->is_used = 1;
	(*square)[x + ((*tet)->coor)[1][0]][y + ((*tet)->coor)[0][0]] =
		'A' + (*tet)->order;
	(*square)[x + ((*tet)->coor)[1][1]][y + ((*tet)->coor)[0][1]] =
		'A' + (*tet)->order;
	(*square)[x + ((*tet)->coor)[1][2]][y + ((*tet)->coor)[0][2]] =
		'A' + (*tet)->order;
	(*square)[x + ((*tet)->coor)[1][3]][y + ((*tet)->coor)[0][3]] =
		'A' + (*tet)->order;
}

void		del_tet(char ***square, t_tetris **tet, const int x, const int y)
{
	(*tet)->is_used = 0;
	(*square)[x + ((*tet)->coor)[1][0]][y + ((*tet)->coor)[0][0]] = '.';
	(*square)[x + ((*tet)->coor)[1][1]][y + ((*tet)->coor)[0][1]] = '.';
	(*square)[x + ((*tet)->coor)[1][2]][y + ((*tet)->coor)[0][2]] = '.';
	(*square)[x + ((*tet)->coor)[1][3]][y + ((*tet)->coor)[0][3]] = '.';
}

int			check_tet(char ***square, t_tetris **tet)
{
	int			i;
	int			j;
	t_tetris	*temp;

	temp = *tet;
	if (!(*tet))
		return (1);
	i = -1;
	while ((*square)[++i])
	{
		j = -1;
		while ((*square)[i][++j])
			if (temp->is_used != 1 && check_if_poss(temp->coor, i, j, *square))
			{
				fill_tet(square, &temp, i, j);
				if (check_tet(square, &((*tet)->next)))
					return (1);
				else
					del_tet(square, &temp, i, j);
			}
	}
	return (0);
}

char		**back_square(int lenght, t_tetris **tets)
{
	char		**temp;

	temp = smallest_square(lenght);
	if (!check_tet(&temp, tets))
		temp = back_square(lenght + 1, tets);
	return (temp);
}
