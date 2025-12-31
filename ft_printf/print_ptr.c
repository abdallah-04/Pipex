/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:47:18 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 19:28:09 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (print_str ("(nil)"));
	count = ptr_len (ptr);
	write(1, "0x", 2);
	print_hex(ptr, 'x');
	return (count + 2);
}
