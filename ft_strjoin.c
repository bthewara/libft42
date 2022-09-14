/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:47:33 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/14 23:51:38 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("\0");
	else
	{
		while (s1[i])
		{
			s[j++] = ss1[i++];
		}
	}
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	return (s);
}
