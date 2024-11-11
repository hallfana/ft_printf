/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:11:19 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	route_arg(va_list ap, char *fmt)
{
	
}

int	ft_printf(const char *fmt, ...)
{
	size_t	len;
	va_list	ap;
	int		i;

	va_start(ap, fmt);
	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len += 0;
			i++;
			continue ;
		}
		print_c((int)fmt[i]);
		len++;
		i++;
	}
	return (0);
}
