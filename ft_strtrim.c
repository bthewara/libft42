/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:56:13 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/15 00:06:17 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
{
	if (!*set)
		return (0);
	else if (c == *set)
		return (1);
	else
		return (is_in(c, ++set));
}

static int	marker(const char *s, const char *set, int bagin)
{
	int		i;
	int		iter;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	iter = 1;
	if (!begin)
	{
		i = s_len - 1;
		iter = -1;
	}
	while (s_len)
	{
		if (is_in(s[i], set) && s[i] != '\0' && i > -1)
		{
			i = i + iter;
			s_len--;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		b;
	int		e;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	b = marker(s1, set, 1);
	e = marker(s1, set, 0) + 1;
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[b], e - b + 1);
	return (s2);
}
