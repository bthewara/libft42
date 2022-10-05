/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:24:49 by bthewara          #+#    #+#             */
/*   Updated: 2022/06/13 13:10:42 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cut(int num, int res)
{
	int		div;
	int		mod;
	char	c;

	div = num / 10;
	mod = num % 10;
	if (div != 0)
		cut(div, res);
	c = '0' + mod;
	ft_putchar_fd(c, res);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n != 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (n == -2147483648)
			{
				n = (-1) * (n / 10);
				cut(n, fd);
				ft_putchar_fd('8', fd);
			}
			else
			{
				n = -n;
				cut(n, fd);
			}		
		}
		else
			cut(n, fd);
	}
	else
		ft_putchar_fd('0', fd);
}
