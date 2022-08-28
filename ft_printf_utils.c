/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:18:38 by zdogan            #+#    #+#             */
/*   Updated: 2022/08/18 13:47:04 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putbase(long double arg, char c, int base)
{
	int		i;
	char	*basex;

	i = 0;
	if (c == 'X')
		basex = "0123456789ABCDEF";
	else
		basex = "0123456789abcdef";
	if (arg < 0)
	{
		arg = -arg;
		write(1, "-", 1);
		i = 1;
	}
	if (arg >= base)
		i += ft_putbase(arg / base, c, base);
	i += write(1, &basex[(unsigned long)arg % base], 1);
	return (i);
}
