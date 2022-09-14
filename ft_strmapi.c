/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <bthewara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:53:18 by bthewara          #+#    #+#             */
/*   Updated: 2022/09/15 00:56:28 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n;
	size_t	i;

	if (!s || !f)
		return (NULL);
	n = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!n)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
