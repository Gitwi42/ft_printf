/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhinojos <mhinojos@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:25:35 by mhinojos          #+#    #+#             */
/*   Updated: 2026/10/10 14:22:13 by mhinojos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "Libft/libft.h"

static	void ft_printhex(unsigned int nb, char *str)
{
	if (nb >= 16)
		ft_printhex(nb / 16, str);
	ft_putchar_fd(str[nb % 16], 1);
}
void	ft_putunnbr_fd(unsigned int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb >= 10)
		ft_putunnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

static	void	ft_moddefine(char afterprc, va_list args)
{
	char	*hex;
	char	*HEX;

	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
	if (afterprc == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (afterprc == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (afterprc == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_printhex(va_arg(args, void *), HEX);
	}
	if (afterprc == 'd' || afterprc == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (afterprc == 'u')
		ft_putunnbr_fd(va_arg(args, unsigned int), 1);
	if (afterprc == 'x')
		ft_printhex(va_arg(args, unsigned int), hex);
	if (afterprc == 'X')
		ft_printhex(va_arg(args, unsigned int), HEX);
	if (afterprc == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	size_t	index;
	int	count;

	index = 0;
	count = 0;
	va_start(args, src);
	while (src[index])
	{
		if (!src[index + 1] && src[index] == '%')
			return (ft_strlen(src) - (count + 1));
		if (src[index] == '%')
		{
			index++;
			count += 2;
			ft_moddefine(src[index], args);
		}
		else
			ft_putchar_fd(src[index], 1);
		index++;
	}
	va_end(args);
	return (ft_strlen(src) - count);
}
