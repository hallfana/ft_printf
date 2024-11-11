/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:18:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 23:02:02 by samberna         ###   ########.fr       */
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
	/*if (fmt[*i + 1] && fmt[*i + 1] == 'p')
		;*/
	if (fmt[*i + 1] && fmt[*i + 1] == 'd')
		*len += ft_print_d((long)va_arg(ap, long));
	if (fmt[*i + 1] && fmt[*i + 1] == 'i')
		*len += ft_print_d((int)va_arg(ap, int));
	if (fmt[*i + 1] && fmt[*i + 1] == 'u')
		*len += ft_print_d((unsigned int)va_arg(ap, unsigned int));
	/*if (fmt[*i + 1] && fmt[*i + 1] == 'x')
		;
	if (fmt[*i + 1] && fmt[*i + 1] == 'X')
		;*/
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

/*
void	main(void)
{
	//printf("real \n%d\n, fake \n%d\n", printf("rehtg:%%:%c:%s:%d:%i:%u:vetvnrej", 'F', "HEY LES MEC", -65984565, -659865, 659865), 
	//ft_printf("rehtg:%%:%c:%s:%d:%i:%u:vetvnrej", 'F', "HEY LES MEC", -65984565, -659865, 659865));
	int i;
	int j;

	printf("\noutput of real:\n");
	i = printf(";%s;R", "");
	printf("\noutput of fake:\n");
	j = ft_printf(";%s;F", "");

	printf("\n\nreal:%d,fake:%d",i,j);
}*/
