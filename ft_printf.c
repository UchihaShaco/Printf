/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:16:51 by jalwahei          #+#    #+#             */
/*   Updated: 2022/11/11 15:47:25 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (c == 'x' || c == 'X')
		p += ft_hex_base(va_arg(arg, unsigned int), c);
	else if (c == 'p')
	{
		p += write(1, "0x", 2);
		p += ft_hex_base(va_arg(arg, unsigned long), 'x');
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

// #include<stdio.h>
// #include<printf.h>
// #include<unistd.h>

// int	main(void)
// {
// 	int				i;
// 	int				d;
// 	unsigned int	l;
// 	unsigned int	kira;
// 	void			*p;

// 	p = (int *)0;
// 	i = 0;
// 	d = -0;
// 	kira = 4294967295;
// 	l = 0;
// 	printf("Original = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
// 	ft_printf("Mine     = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
// 	write(1, "\n\n", 2);
// 	printf("Original = u:[%u] x:[%x] X:[%X] s:[%s]\n", kira, l, l,
// 		"Uciha Jafar");
// 	ft_printf("Mine     = u:[%u] x:[%x] X:[%X] s:[%s]\n", kira, l, l,
// 		"Uciha Jafar");
// }