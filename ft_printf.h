/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:19:39 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 21:25:31 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flag
{
	int	type;
	int	width;
	int	moin;
	int	zero;
	int	point;
	int	star;
}	t_flag;


# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_c(char	c);
int	ft_route_arg(va_list ap, const char *fmt, int i);

#endif