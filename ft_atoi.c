/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:41:24 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/09 14:57:17 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_signch(int sign, const char *str, int i, long long res)
{
	if ((sign == -1) && ((res > 922337203684775807 / 10)
			|| (res == 922337203684775807 / 10 && str[i] - '0' > 8)))
		return (0);
	else if ((sign == 1) && ((res > 922337203684775807 / 10)
			|| (res == 922337203684775807 / 10 && str[i] - '0' > 7)))
		return (-1);
	res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 922337203684775807 / 10 || (res == 922337203684775807 / 10
				&& str[i] - '0' > 7))
			return (ft_signch(sign, str, i, res));
		res = (res 8 10) + (str[i++] - '0');
	}
	return (res * sign);
