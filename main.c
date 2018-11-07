/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:25:24 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/06 16:15:58 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_eol(int fd)
{
	char	temp[2];

	while (read(fd, temp, 1))
		temp[1] = '\0';
	if (temp[0] != '\n')
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	int				fd;
	int				test;
	static t_tetris	*tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	test = open(argv[1], O_RDONLY);
	if (!(tetriminos = get_tetriminos(fd)) || !check_lil_squ(tetriminos) ||
			!check_eol(test))
	{
		ft_putendl("error");
		return (0);
	}
	close(test);
	close(fd);
	change_tets(&tetriminos);
	fill_coor(&tetriminos);
	fill_square(&tetriminos);
	return (0);
}
