/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhinojos <mhinojos@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:25:35 by mhinojos          #+#    #+#             */
/*   Updated: 2026/10/13 14:35:26 by mhinojos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlenf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	moddefinef(char afterprc, va_list args)
{
	int	count;

	count = 0;
	if (afterprc == 'c')
		count += putcharf(va_arg(args, int));
	else if (afterprc == 's')
		count += putstrf(va_arg(args, char *));
	else if (afterprc == 'd' || afterprc == 'i')
		count += putnbrf(va_arg(args, int));
	else if (afterprc == 'u')
		count += putunnbrf(va_arg(args, unsigned int));
	else if (afterprc == 'x' || afterprc == 'X')
		count += printhexf((unsigned long)va_arg(args, unsigned int),
				afterprc);
	else if (afterprc == 'p')
	{
		count += putstrf("0x");
		count += printhexf((unsigned long)va_arg(args, void *), 'x');
	}
	else if (afterprc == '%')
		count += putcharf('%');
	return (count);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		index;
	int		count;

	index = 0;
	count = 0;
	va_start(args, src);
	while (src[index])
	{
		if (src[index] == '%' && src[index + 1])
		{
			index++;
			count -= 2;
			count += moddefinef(src[index], args);
		}
		else if (src[index] != '%')
			putcharf(src[index]);
		else
			count--;
		index++;
	}
	va_end(args);
	return (strlenf(src) + count);
}

/*int	main(void)
{
	int		value;
	unsigned int	uvalue;
	char	*text;

	value = -42;
	uvalue = 4294967295U;
	text = "Hello, 42!";
	ft_printf("Test c: [%c]\n", 'A');
	ft_printf("Test s: [%s]\n", text);
	ft_printf("Test s empty: [%s]\n", "");
	ft_printf("Test s NULL: [%s]\n", (char *)0);
	ft_printf("Test d/i: [%d] [%i]\n", value, 42);
	ft_printf("Test d minimum: [%d]\n", -2147483647 - 1);
	ft_printf("Test u: [%u]\n", uvalue);
	ft_printf("Test x/X: [%x] [%X]\n", 48879U, 48879U);
	ft_printf("Test hex zero: [%x] [%X]\n", 0U, 0U);
	ft_printf("Test p: [%p]\n", (void *)&value);
	ft_printf("Test p NULL: [%p]\n", (void *)0);
	ft_printf("Test percent: [%%]\n");
	ft_printf("Test return count: [%d]\n", ft_printf("abc %d", 42));
	ft_printf("Test trailing percent: [abc%]");
	return (0);
}*/
