/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhinojos <mhinojos@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:02:11 by mhinojos          #+#    #+#             */
/*   Updated: 2026/10/13 14:21:10 by mhinojos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putcharf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstrf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	printhexf(unsigned long n, char c)
{
	char	*str;
	int		count;

	count = 0;
	if (!n)
	{
		count += putcharf('0');
		return (count);
	}
	str = "0123456789abcdef";
	if (c == 'X')
		str = "0123456789ABCDEF";
	if (n >= 16)
		count += printhexf(n / 16, c);
	count += putcharf(str[n % 16]);
	return (count);
}

int	putnbrf(int n)
{
	long	nb;
	char	c;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nb >= 10)
		count += putnbrf(nb / 10);
	c = (nb % 10) + '0';
	count += putcharf(c);
	return (count);
}

int	putunnbrf(unsigned int n)
{
	long	nb;
	char	c;
	int		count;

	count = 0;
	nb = (long)n;
	if (nb >= 10)
		count += putunnbrf(nb / 10);
	c = (nb % 10) + '0';
	count += putcharf(c);
	return (count);
}
