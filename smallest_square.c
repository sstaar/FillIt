/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:24:32 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/07 11:19:48 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_nbr_tets(t_tetris *lst)
{
	t_tetris	*temp;

	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp->order + 1);
}

int			get_lenght(t_tetris *lst)
{
	int		i;
	int		nbr;

	nbr = get_nbr_tets(lst);
	i = 1;
	while (i <= nbr * 4)
	{
		if (i * i >= nbr * 4)
			return (i);
		i++;
	}
	return (0);
}

char		**smallest_square(const int lenght)
{
	char	**temp;
	int		width;
	int		i;
	int		j;

	i = 0;
	width = lenght;
	if (!(temp = (char**)malloc(sizeof(char*) * (width + 1))))
		return (NULL);
	temp[width] = 0;
	while (i < width)
	{
		if (!(temp[i] = (char*)malloc(sizeof(char) * (width + 1))))
			return (NULL);
		j = -1;
		temp[i][width] = '\0';
		while (++j < width)
		{
			temp[i][j] = '.';
		}
		i++;
	}
	return (temp);
}

void		fill_coor(t_tetris **original)
{
	t_tetris	*temp;

	temp = *original;
	while (temp)
	{
		temp->coor = get_coor(temp);
		temp = temp->next;
	}
}
