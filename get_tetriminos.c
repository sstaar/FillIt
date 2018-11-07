/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:00:36 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/07 11:21:39 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				treatment(t_tetris **lst, char *line, int *or)
{
	static	int	i;

	if (line[0] == '\0')
	{
		((*lst)->tet)[i] = 0;
		(*or)++;
		if (!((*lst)->next = (t_tetris*)malloc(sizeof(t_tetris))))
			return (0);
		*lst = (*lst)->next;
		(*lst)->next = NULL;
		if (!((*lst)->tet = (char**)malloc(sizeof(char*) * 5)))
			return (0);
		i = 0;
	}
	else
	{
		((*lst)->tet)[i] = ft_strnew(0);
		((*lst)->tet)[i] = ft_strjoin(((*lst)->tet)[i], line);
		(*lst)->order = *or;
		i++;
	}
	return (i);
}

t_tetris		*get_tetriminos(const int fd)
{
	t_tetris	*temp;
	int			or;
	char		*temp2;
	t_tetris	*temp3;
	int			check;

	check = 0;
	or = 0;
	if (!(temp = (t_tetris*)malloc((sizeof(t_tetris)))))
		return (NULL);
	temp3 = temp;
	temp->next = NULL;
	temp->tet = (char**)malloc(sizeof(char*) * 5);
	while (get_next_line(fd, &temp2))
	{
		if (treatment(&temp, temp2, &or) > 4 || or >= 26)
			return (NULL);
		check++;
	}
	if (check == 0 || or > 26)
		return (NULL);
	free(temp2);
	if (!temp3)
		return (NULL);
	return (temp3);
}

void			fill_square(t_tetris **original)
{
	int			ini_len;
	char		**temp;

	ini_len = get_lenght(*original);
	fill_coor(original);
	temp = back_square(ini_len, original);
	display_square(temp);
}
