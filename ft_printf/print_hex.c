/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:15:36 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 19:28:47 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hex_conversion(unsigned long num, const char *str)
{
	int	indx;

	indx = 0;
	if (num >= 16)
	{
		hex_conversion (num / 16, str);
	}
	indx = num % 16;
	write(1, &str[indx], 1);
}

int	print_hex(unsigned long num, char format)
{
	const char	*hex_char;
	int			count;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'X')
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	count = hex_len(num);
	hex_conversion(num, hex_char);
	return (count);
}
