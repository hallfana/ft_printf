/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:19:39 by samberna          #+#    #+#             */
/*   Updated: 2024/11/12 01:29:22 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_print_c(char c);
int		ft_print_s(char	*str);
int		ft_print_d(int nb);
void	ft_route_arg(va_list ap, const char *fmt, int *i, int *len);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t sw);
size_t	ft_strlen(const char *s);
int		ft_print_u(unsigned int n);
int		nblen_u(long n);
int		ft_print_x(unsigned int nb);
int		ft_print_x_big(unsigned int nb);
char	*ft_toupper_hex(char *c);
int		ft_print_p(unsigned long long nb);

#endif