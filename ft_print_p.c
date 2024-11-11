/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:39:56 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 00:55:38 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nblen_x_ull(unsigned long long n)
{
    int	len;

	len = 0;
    if (n == 0)
		return 1;
    while (n > 0)
	{
        n /= 16;
        len++;
    }
    return (len);
}

char *ft_to_base_16_ull(unsigned long long n)
{
    long	nb;
	char	*dst;
    int 	i;

	nb = n;
    if (n == 0)
		return ft_strdup("0");
    dst = (char *)malloc(sizeof(char) * (nblen_x_ull(nb) + 1));
    if (!dst)
        return NULL;
    i = nblen_x_ull(nb) - 1;
	while (nb > 0)
	{
		if (nb % 16 < 10)
        	dst[i--] = (nb % 16) + 48;
		else
			dst[i--] = (nb % 16) + 87;
        nb /= 16;
    }
    dst[nblen_x_ull(n)] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = 0;
	return (str);
}

int ft_print_p(unsigned long long nb)
{
    char	*s;
	char	*d;
    int		l;

    s = ft_to_base_16_ull(nb);
	l = 0;
	if (s && ft_strlen(s) > 0)
	{
		d = ft_strjoin("0x", s);
		l = ft_print_s(d);
		free(d);
	}
	free(s);
	return (l);
}