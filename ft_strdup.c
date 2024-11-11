/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:54:57 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 22:33:54 by samberna         ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}