/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:11:08 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:31:15 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nblen_u(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_u_itoa(unsigned int n)
{
	long	nb;
	char	*dst;
	int		i;

	nb = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	dst = (char *)malloc(sizeof(char) * (nblen_u(nb) + 1));
	if (!dst)
		return (NULL);
	i = nblen_u(nb) - 1;
	while (nb > 0)
	{
		dst[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	dst[nblen_u(n)] = '\0';
	return (dst);
}

int	ft_print_u(unsigned int nb)
{
	char	*s;
	int		l;

	s = ft_u_itoa(nb);
	l = ft_print_s(s);
	free(s);
	return (l);
}
