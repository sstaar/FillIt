/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:57:55 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/07 11:08:30 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		change_line(char *str, const int or)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = 'A' + or;
		i++;
	}
}

void		change_tets(t_tetris **tets)
{
	t_tetris	*temp;
	int			i;

	temp = *tets;
	while (temp)
	{
		i = 0;
		while ((temp->tet)[i])
		{
			change_line((temp->tet)[i], temp->order);
			i++;
		}
		temp = temp->next;
	}
}

void		display_square(char **square)
{
	int	i;

	i = -1;
	while (square[++i])
		ft_putendl(square[i]);
}
