/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:01:39 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/31 15:04:51 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_origin(t_tetris *lst)
{
	t_tetris	*temp;
	int			i;
	int			j;
	int			*temp2;

	temp2 = (int*)malloc(sizeof(int) * 2);
	i = 0;
	temp = lst;
	while ((temp->tet)[i])
	{
		j = 0;
		while ((temp->tet)[i][j])
		{
			if ((temp->tet)[i][j] >= 'A' && (temp->tet)[i][j] <= 'Z')
			{
				temp2[0] = j;
				temp2[1] = i;
				return (temp2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		**get_abs_coor(t_tetris *lst)
{
	int		**temp;
	int		i;
	int		j;
	int		t;

	temp = (int**)malloc(sizeof(int*) * 2);
	temp[0] = (int*)malloc(sizeof(int) * 4);
	temp[1] = (int*)malloc(sizeof(int) * 4);
	i = 0;
	j = 0;
	t = 0;
	while ((lst->tet)[i])
	{
		j = -1;
		while ((lst->tet)[i][++j])
			if ((lst->tet)[i][j] >= 'A' && (lst->tet)[i][j] <= 'Z')
			{
				temp[0][t] = j;
				temp[1][t] = i;
				t++;
			}
		i++;
	}
	return (temp);
}

int		**get_coor(t_tetris *lst)
{
	int		*start;
	int		**temp;
	int		i;

	i = 0;
	start = get_origin(lst);
	temp = get_abs_coor(lst);
	while (i < 4)
	{
		temp[0][i] -= start[0];
		temp[1][i] -= start[1];
		i++;
	}
	return (temp);
}
