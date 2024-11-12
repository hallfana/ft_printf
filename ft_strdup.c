/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:54:57 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:27:59 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*c;

	i = 0;
	len = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strndup(const char *s, size_t sw)
{
	size_t	i;
	size_t	len;
	char	*c;

	i = 0;
	len = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (sw + 1));
	if (!c)
		return (NULL);
	while (i < len && i < sw)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_toupper_hex(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 97 && c[i] <= 122)
			c[i] = c[i] - 32;
		i++;
	}
	return (c);
}
