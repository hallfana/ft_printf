/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:11:08 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 23:26:15 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_u(int	nb)
{
	if ((long long)nb < 0)
		return (ft_print_s("4294862765"));
	else
		return (ft_print_d(nb));
}