/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <samberna@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:19:39 by samberna          #+#    #+#             */
/*   Updated: 2024/11/11 23:51:18 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_print_c(char	c);
int		ft_print_s(char	*str);
int 	ft_print_d(int	nb);
void	ft_route_arg(va_list ap, const char *fmt, int *i, int *len);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t sw);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_print_u(unsigned int n);

#endif