/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:22:26 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/06 15:54:00 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_contact(t_tetris *temp)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while ((temp->tet)[++i])
	{
		j = -1;
		while ((temp->tet)[i][++j])
			if ((temp->tet)[i][j] == '#')
			{
				if (i + 1 < 4 && i + 1 >= 0 && (temp->tet)[i + 1][j] == '#')
					count++;
				if (i - 1 < 4 && i - 1 >= 0 && (temp->tet)[i - 1][j] == '#')
					count++;
				if (j + 1 < 4 && j + 1 >= 0 && (temp->tet)[i][j + 1] == '#')
					count++;
				if (i - 1 < 4 && j - 1 >= 0 && (temp->tet)[i][j - 1] == '#')
					count++;
			}
	}
	if (count != 8 && count != 6)
		return (0);
	return (1);
}

int		check_lists(t_tetris *lst)
{
	t_tetris	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->is_used != 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

char	*switch_str(t_tetris *temp)
{
	int			i;
	char		*temp1;

	temp1 = ft_strnew(0);
	i = 0;
	while ((temp->tet)[i])
	{
		temp1 = ft_strjoin(temp1, (temp->tet)[i]);
		i++;
	}
	return (temp1);
}

int		check_comp(t_tetris *temp)
{
	int			i;
	char		*temp1;
	int			hash_count;
	int			point_count;

	temp1 = switch_str(temp);
	if (ft_strlen(temp1) != 16)
		return (0);
	point_count = 0;
	hash_count = 0;
	i = -1;
	while (temp1[++i])
	{
		if (temp1[i] == '.')
			point_count++;
		else if (temp1[i] == '#')
			hash_count++;
		else
			return (0);
	}
	free(temp1);
	temp1 = NULL;
	if (point_count != 12 || hash_count != 4)
		return (0);
	return (1);
}

int		check_lil_squ(t_tetris *original)
{
	int			i;
	t_tetris	*temp;

	temp = original;
	while (temp)
	{
		i = -1;
		while ((temp->tet)[++i])
		{
			if (ft_strlen((temp->tet)[i]) != 4)
				return (0);
		}
		if (i != 4 || !check_comp(temp) || !check_contact(temp))
			return (0);
		temp = temp->next;
	}
	return (1);
}
