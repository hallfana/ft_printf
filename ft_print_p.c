/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:39:56 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:20:14 by samberna         ###   ########.fr       */
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
	unsigned long long	n_tmp;
	char				*dst;
    int 				i;

	n_tmp = n;
    if (n == 0)
		return ft_strdup("0");
    dst = (char *)malloc(sizeof(char) * (nblen_x_ull(n) + 1));
    if (!dst)
        return NULL;
    i = nblen_x_ull(n) - 1;
	while (n_tmp > 0)
	{
		if (n_tmp % 16 < 10)
        	dst[i--] = (n_tmp % 16) + 48;
		else
			dst[i--] = (n_tmp % 16) + 87;
        n_tmp /= 16;
    }
    dst[nblen_x_ull(n)] = '\0';
	return (dst);
}

int ft_print_p(unsigned long long nb)
{
    char	*s;
    int 	l;

	if (!nb)
		return (ft_print_s("(nil)"));
	l = 0;
    s = ft_to_base_16_ull(nb);
	if (s && ft_strlen(s) > 0)
		l += ft_print_s("0x");
	l += ft_print_s(s);
	free(s);
	return (l);
}