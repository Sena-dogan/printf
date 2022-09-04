/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:18:33 by zdogan            #+#    #+#             */
/*   Updated: 2022/08/18 13:45:26 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putbase(va_arg(ap, int), c, 10);
	else if (c == 'u')
		i += ft_putbase(va_arg(ap, unsigned int), c, 10);
	else if (c == 'x' || c == 'X')
		i += ft_putbase(va_arg(ap, unsigned int), c, 16);
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putbase(va_arg(ap, unsigned long long int), c, 16);
	}
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			i += ft_control(str[++count], ap);
			count++;
		}
		else
		{
			i += ft_putchar(str[count]);
			count++;
		}
	}
	return (i);
}
