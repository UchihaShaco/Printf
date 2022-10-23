/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:16:51 by jalwahei          #+#    #+#             */
/*   Updated: 2022/10/22 16:49:17 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdarg.h>

// void printmini(char *str, ...)
// {
// 	int arg1;
// 	char key;
// 	va_list args;
// 	va_start(args, str);
// 	while (*str != '\0')
// 	{
// 		if (*str == '%')
// 		{
// 			while(*str == '%')
// 			{
		
// 			key = *(++str);
// 			if (key)
// 			{
// 				if (key == 'd')
// 				{
// 					arg1 = va_arg(args, int);
// 					printf("%d", arg1);
// 					break;
// 				}
// 				else if (key == '%')
// 				{
// 					putchar(key);
// 					break;
// 				}
// 				else if (key == 's')
// 				{
// 					printf("%s", va_arg(args, char *));
// 					break;
// 				}
// 			}
			
// 		}
// 		}
// 		else
// 		putchar(*str);
// 		str++;
// 	}
// 	va_end(args);
// }
// int main()
// {
// 	int i = 0;
// 	float j = 0.0;
// 	char *str = ":D:D:D:D:D";


// 	void *x = &i;
// 	printmini("SHE MADE IT WITH SHALALAEEET  GG %s %i  bla bla  ",  str, i);
// 	return 0;
// }

#include "ft_printf.h"

int	ft_check(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		p += ft_x(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		p += ft_x(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		p += ft_putstr("0x");
		p += ft_pointer(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		p += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (p);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			j++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			j += ft_check(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (j);
}

// int	main()
// {
// 	char	*s = "ola";
// 	char	*c;
// 	c = s;
// 	ft_printf("alo alo %d %s %c %i %% %u %s %x %X %p \n", 123, "OUUU", 'o', -59, -10, NULL, 202, 202, &c);
// 	printf("alo alo %d %s %c %i %% %u %s %x %X %p \n", 123, "OUUU", 'o', -59, -10, NULL, 202, 202, &c);
// 	ft_printf("%%\n");
// 	printf("%%%");
// }