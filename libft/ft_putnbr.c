/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:34:42 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/04 13:34:43 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = n * -1;
		ft_putchar('-');
	}
	else
		i = n;
	if (i <= 9)
		ft_putchar('0' + i);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
