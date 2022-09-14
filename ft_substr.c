/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:37:54 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/14 23:44:50 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while ((char)s[start] && (size_t)i < len)
	{
		sub[i] = (char)s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}
