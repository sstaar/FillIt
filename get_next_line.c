/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 07:19:57 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/20 11:35:00 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*get_list(t_list **list, const int fd)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *list;
	while (temp && (int)temp->content_size != fd)
		temp = temp->next;
	if (temp && (int)temp->content_size == fd)
		return (temp);
	temp2 = (t_list*)malloc(sizeof(t_list));
	if (!(temp2->content = ft_strnew(BUFF_SIZE)))
		return (NULL);
	temp2->content_size = fd;
	temp2->next = NULL;
	ft_lstadd(list, temp2);
	return (*list);
}

int			is_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

char		*fill_line(char **src)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while ((*src)[i] && (*src)[i] != '\n')
		i++;
	if (!(temp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while ((*src)[i] && (*src)[i] != '\n')
	{
		temp[i] = (*src)[i];
		i++;
	}
	temp[i] = '\0';
	j = 0;
	if ((*src)[i] == '\n')
		i++;
	while ((*src)[i])
		(*src)[j++] = (*src)[i++];
	while ((*src)[j])
		(*src)[j++] = '\0';
	return (temp);
}

int			get_parts(char **line, t_list **temp, t_list **list, const int fd)
{
	*temp = get_list(list, fd);
	*line = ft_strnew(0);
	if ((*temp)->content && is_line((char*)(*temp)->content))
	{
		*line = ft_strjoin(*line, fill_line((char**)&(*temp)->content));
		return (1);
	}
	if ((*temp)->content && !is_line((char*)(*temp)->content))
		*line = ft_strjoin(*line, fill_line((char**)&(*temp)->content));
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	t_list			*temp;
	int				size;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 ||
			!(char*)malloc(sizeof(char) * BUFF_SIZE))
		return (-1);
	if (get_parts(line, &temp, &list, fd))
		return (1);
	while ((size = read(fd, temp->content, BUFF_SIZE)) != 0)
	{
		if (size == -1)
			return (-1);
		((char*)temp->content)[size] = '\0';
		if (is_line((char*)temp->content) == 0)
			*line = ft_strjoin(*line, fill_line((char**)&temp->content));
		else
		{
			*line = ft_strjoin(*line, fill_line((char**)&temp->content));
			return (1);
		}
	}
	if ((*line)[0] != '\0')
		return (1);
	return (0);
}
