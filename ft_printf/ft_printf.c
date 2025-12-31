/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:14:40 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 18:51:29 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cheak_format(char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(arg, int));
	else if (format == 's')
		count += print_str(va_arg(arg, char *));
	else if (format == 'i' || format == 'd')
		count += print_int(va_arg(arg, int));
	else if (format == 'x' || format == 'X')
		count += print_hex(va_arg(arg, unsigned int), format);
	else if (format == 'p')
		count += print_ptr(va_arg(arg, unsigned long));
	else if (format == 'u')
		count += print_unsigned(va_arg(arg, unsigned int));
	else if (format == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += cheak_format(format[i], args);
		}
		else
		{
			count += print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
