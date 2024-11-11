/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:49:41 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_route_arg(va_list ap, const char *fmt, int *i)
{
	int	printed;

	printed = 0;
	if (fmt[*i + 1] && fmt[*i + 1] == 'c')
		printed += ft_print_c((char)va_arg(ap, int));
	if (fmt[*i + 1] && fmt[*i + 1] == 's')
		printed += ft_print_s((char*)va_arg(ap, char*));
	/*if (fmt[*i + 1] && fmt[*i + 1] == 'p')
		;*/
	if (fmt[*i + 1] && fmt[*i + 1] == 'd')
		printed += ft_print_d((long)va_arg(ap, long));
	if (fmt[*i + 1] && fmt[*i + 1] == 'i')
		printed += ft_print_d((long)va_arg(ap, int));
	if (fmt[*i + 1] && fmt[*i + 1] == 'u')
		printed += ft_print_d((long)va_arg(ap, unsigned int));
	/*if (fmt[*i + 1] && fmt[*i + 1] == 'x')
		;
	if (fmt[*i + 1] && fmt[*i + 1] == 'X')
		;
	if (fmt[*i + 1] && fmt[*i + 1] == '%')*/
		//printed += ft_print_pourcent();
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
	ft_printf("rehtg:%c:%s:%d:%i:%u:vetvnrej", 'F', "HEY LES MEC", -659865, -659865, 659865);
}
