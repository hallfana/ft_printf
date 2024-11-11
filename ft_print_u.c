/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:11:08 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 23:13:56 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nblen_u(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*dst;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	dst = (char *)malloc(sizeof(char) * (nblen(n) + 1));
	if (!dst)
		return (NULL);
	if (!dst)
		return (NULL);
	i = nblen(n) - 1;
	while (n > 0)
	{
		dst[i--] = (n % 10) + '0';
		n /= 10;
	}
	dst[nblen(n)] = '\0';
	return (dst);
}

int ft_print_u(int	nb)
{
	char	*s;
	int		l;

	s = ft_itoa(nb);
	l = ft_print_s(s);
	free(s);
	return (l);
}