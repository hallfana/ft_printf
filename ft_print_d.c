/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:39:35 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:49:40 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_l(long nb, int *len)
{
	if (nb < 0)
	{
		nb *= -1;
		*len += ft_print_c('-');
	}
	if (nb < 10)
		*len += ft_print_c((char)(nb + '0'));
	else
	{
		ft_putnbr_l(nb / 10, len);
		*len += ft_print_c((char)((nb % 10) + '0'));
	}
}

int ft_print_d(long	nb)
{
	int	len;

	len = 0;
	ft_putnbr_l(nb, &len);
	return len;
}