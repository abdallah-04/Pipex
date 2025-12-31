/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:45:44 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/01 19:07:21 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int num)
{
	int		count;
	long	n;

	count = 0;
	n = num;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	hex_len(unsigned int num)
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

int	unsigned_len(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
