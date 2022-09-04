/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:18:26 by zdogan            #+#    #+#             */
/*   Updated: 2022/08/18 11:22:56 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putbase(long double arg, char c, int base);
int	ft_control(char c, va_list ap);
int	ft_printf(const char *str, ...);

#endif
