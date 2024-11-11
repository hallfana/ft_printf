/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:20:35 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_route_arg(va_list ap, char *fmt, int i)
{
	int	printed;

	printed = 0;
	if (fmt[i + 1] == 'c')
		printed += ft_print_c((int)va_arg(ap, int));
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;
	int		i;

	va_start(ap, fmt);
	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len += ft_route_arg(ap, fmt, i);
			i++;
			continue ;
		}
		ft_print_c((int)fmt[i]);
		len++;
		i++;
	}
	return (0);
}
