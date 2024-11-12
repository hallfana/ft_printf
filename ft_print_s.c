/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:41:50 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:23:05 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char	*str)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (!str)
		return (ft_print_s("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		p++;
		i++;
	}
	return (p);
}
