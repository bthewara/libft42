/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:34:52 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/15 00:52:24 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	new_putnbr(int num)
{
	unsigned int	nb;

	nb = num;
	if (nb == 0)
		return (0 + '0');
	if (nb > 0)
	{
		new_putnbr(nb / 10);
		nb %= 10;
	}
	return (nb + '0');
}

static int	is_neg(int num)
{
	if (num < 0)
		return (1);
	return (0);
}

static size_t	get_digit(int n)
{
	size_t			i;
	unsigned int	num;

	i = 0;
	if (is_neg(n))
	{
		num = (unsigned int)-n;
		i++;
	}
	else
		num = (unsigned int)n;
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;
	int				i;

	len = get_digit(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (is_neg(n))
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	while (i++ <= (int)len - 1)
	{
		str[(int)len - i] = new_putnbr(num);
		num /= 10;
	}
	if (is_neg(n))
		str[0] = '-';
	str[len] = '\0';
	return (str);
}
