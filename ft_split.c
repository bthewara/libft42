/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:39:06 by bthewara          #+#    #+#             */
/*   Updated: 2022/06/13 12:33:06 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array, int i)
{
	while (i > -1)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static char	*bypass(char *s, char c)
{
	if (*s == c)
	{
		while (*(s + 1) == c)
			s++;
		return (s + 1);
	}
	else
		return (s);
}

static char	**ft_fill(char **split, size_t size, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < size - 1)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		split[i] = (char *)malloc((end - start + 1) * sizeof(char));
		if (!split[i])
		{
			ft_free(split, i - 1);
			return (NULL);
		}
		ft_strlcpy(split[i], &s[start], end - start + 1);
		start = end;
		i++;
	}
	split[size - 1] = NULL;
	return (split);
}

static int	wordcount(const char *s, char c)
{
	int		wc;
	char	*str;

	wc = 0;
	str = (char *)s;
	str = bypass(str, c);
	while (*str)
	{
		while (*str != c && *str != '\0')
			str++;
		if (*str == c)
		{
			str = bypass(str, c);
			wc++;
		}
		else if (*str == '\0')
			wc++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		wc;

	if (!s)
		return (NULL);
	if (*s == '\0')
		wc = 0;
	else if (c == '\0')
		wc = 1;
	else
		wc = wordcount(s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (*s == '\0')
		split[0] = NULL;
	else if (c == '\0')
	{
		split[0] = ft_strdup(s);
		split[1] = NULL;
	}
	else
		split = ft_fill(split, wc + 1, s, c);
	return (split);
}
