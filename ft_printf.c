#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "includes/libft.h"
#include "printf.h"

void ft_arg_router(int	c)
{
	
}

void ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_incharset(format[i + 1], CHARSET))
		{
			ft_arg_router(format[i + 1]);
			i += 2;
			continue ;
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
}
int main(int argc, char **argv)
{
	ft_printf("first1:%s first2:%s first3:%s first4:%s", "HELLO1", "HELLO2", "HELLO3", "HELLO4");
	return (EXIT_SUCCESS);
}