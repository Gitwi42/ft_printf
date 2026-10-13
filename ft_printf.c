/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhinojos <mhinojos@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:25:35 by mhinojos          #+#    #+#             */
/*   Updated: 2026/10/13 14:21:34 by mhinojos         ###   ########.fr       */
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
