/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:39:56 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 00:58:31 by samberna         ###   ########.fr       */
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

int ft_print_p(unsigned long long nb)
{
    char	*s;
    int 	l;

    s = ft_to_base_16_ull(nb);
	if (s && ft_strlen(s) > 0)
		l += ft_print_s("0x");
	l = ft_print_s(s);
	free(s);
	return (l);
}