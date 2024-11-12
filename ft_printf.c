/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:08:09 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_is_prefix(char c)
{
	int		i;
	char	*charset;

	charset = "cspdiuxX%";
	i = -1;
	while (charset[++i])
	{
		if ((char)c == charset[i])
			return (1);
	}
	return (0);
}

void	ft_route_arg(va_list ap, const char *fmt, int *i, int *len)
{
	if (fmt[*i + 1] && fmt[*i + 1] == 'c')
		*len += ft_print_c((char)va_arg(ap, int));
	if (fmt[*i + 1] && fmt[*i + 1] == 's')
		*len += ft_print_s((char*)va_arg(ap, char*));
	if (fmt[*i + 1] && fmt[*i + 1] == 'p')
		*len += ft_print_p((unsigned long long)va_arg(ap, unsigned long long));
	if (fmt[*i + 1] && fmt[*i + 1] == 'd')
		*len += ft_print_d((long)va_arg(ap, long));
	if (fmt[*i + 1] && fmt[*i + 1] == 'i')
		*len += ft_print_d((int)va_arg(ap, int));
	if (fmt[*i + 1] && fmt[*i + 1] == 'u')
		*len += ft_print_u((unsigned int)va_arg(ap, unsigned int));
	if (fmt[*i + 1] && fmt[*i + 1] == 'x')
		*len += ft_print_x((unsigned int)va_arg(ap, unsigned int));
	if (fmt[*i + 1] && fmt[*i + 1] == 'X')
		*len += ft_print_X((unsigned int)va_arg(ap, unsigned int));
	if (fmt[*i + 1] && fmt[*i + 1] == '%')
		len += ft_print_c('%');
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
		if (fmt[i] == '%' && ft_is_prefix(fmt[i + 1]))
		{
			if (fmt[i + 1] == '%')
				len += ft_print_c('%');
			else
				ft_route_arg(ap, fmt, &i, &len);
			i += 2;
			continue ;
		}
		ft_print_c(fmt[i]);
		len++;
		i++;
	}
	return (len);
}

/*void	main(void)
{
	//printf("real \n%d\n, fake \n%d\n", printf("rehtg:%%:%c:%s:%d:%i:%u:vetvnrej", 'F', "HEY LES MEC", -65984565, -659865, 659865), 
	//ft_printf("rehtg:%%:%c:%s:%d:%i:%u:vetvnrej", 'F', "HEY LES MEC", -65984565, -659865, 659865));
	int i;
	int j;

	int g = 45;

	printf("\noutput of real:\n");
	i = printf(";%p;R", __LONG_MAX__);
	printf("\noutput of fake:\n");
	j = ft_printf(";%p;F", __LONG_MAX__);

	printf("\n\nreal:%d,fake:%d",i,j);
}*/