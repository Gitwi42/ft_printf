/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhinojos <mhinojos@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:02:32 by mhinojos          #+#    #+#             */
/*   Updated: 2026/10/13 14:23:23 by mhinojos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *src, ...);
int	putunnbrf(unsigned int n);
int	putnbrf(int n);
int	printhexf(unsigned long n, char c);
int	putstrf(char *s);
int	putcharf(char c);

#endif
