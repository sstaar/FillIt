/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:24:10 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/04 14:24:16 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	lencal(int n)
{
	size_t			len;
	unsigned int	j;

	len = 0;
	j = n;
	if (n < 0)
	{
		j = -n;
		len++;
	}
	while (j > 9)
	{
		j /= 10;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;

	i = lencal(n) - 1;
	if (!(temp = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	temp[i + 1] = '\0';
	j = n;
	if (n < 0)
	{
		j = -n;
		temp[0] = '-';
	}
	while (j > 9)
	{
		temp[i] = (j % 10) + '0';
		j /= 10;
		i--;
	}
	temp[i] = (j % 10) + '0';
	return (temp);
}
