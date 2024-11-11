/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:18:23 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 00:32:48 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nblen_x(long n)
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

char *ft_to_base_16(unsigned int n)
{
    long	nb;
	char	*dst;
    int 	i;

	nb = (long)n;
    if (n == 0)
		return ft_strdup("0");
    dst = (char *)malloc(sizeof(char) * (nblen_x(nb) + 1));
    if (!dst)
        return NULL;
    i = nblen_x(nb) - 1;
	while (nb > 0)
	{
		if (nb % 16 < 10)
        	dst[i--] = (nb % 16) + 48;
		else
			dst[i--] = (nb % 16) + 87;
        nb /= 16;
    }
    dst[nblen_x(n)] = '\0';
	return (dst);
}

int ft_print_x(unsigned int nb)
{
    char	*s;
    int		l;

    s = ft_to_base_16(nb);
	l = ft_print_s(s);
	free(s);
	return (l);
}

int ft_print_X(unsigned int nb)
{
    char	*s;
    int 	l;

    s = ft_to_base_16(nb);
	while (*s)
		*s = *s - 32;
	l = ft_print_s(s);
	free(s);
	return (l);
}