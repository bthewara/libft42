/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:09:05 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/15 01:14:46 by bthewara         ###   ########.fr       */
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
			if (n == -214783648)
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
