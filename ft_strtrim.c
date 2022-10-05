/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:32 by bthewara          #+#    #+#             */
/*   Updated: 2022/06/13 12:25:31 by bthewara         ###   ########.fr       */
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

static int	marker(const char *s, const char *set, int begin)
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
	if (b > e)
		b = e;
	s2 = (char *)malloc((e - b + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[b], e - b + 1);
	return (s2);
}
