/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:30:18 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_route_arg(va_list ap, const char *fmt, int *i)
{
	int	printed;

	printed = 0;
	if (fmt[*i + 1] && fmt[*i + 1] == 'c')
		printed += ft_print_c((char)va_arg(ap, int));
	if (printed != 0)
		*i += 2;
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
			len += ft_route_arg(ap, fmt, &i);
			continue ;
		}
		ft_print_c(fmt[i]);
		len++;
		i++;
	}
	return (0);
}

void	main(void)
{
	ft_printf("rehtg:%c:vetvnrej", 'H');
}
