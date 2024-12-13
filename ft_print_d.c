/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:39:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:27:19 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nblen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	dst = (char *)malloc(sizeof(char) * (nblen((long)n) + 1));
	if (!dst)
		return (NULL);
	nb = (long)n;
	if (nb < 0)
	{
		dst[0] = '-';
		nb *= -1;
	}
	if (!dst)
		return (NULL);
	i = nblen((long)n) - 1;
	while (nb > 0)
	{
		dst[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	dst[nblen((long)n)] = '\0';
	return (dst);
}

int	ft_print_d(int nb)
{
	char	*s;
	int		l;

	s = ft_itoa(nb);
	l = ft_print_s(s);
	free(s);
	return (l);
}
