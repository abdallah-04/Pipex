/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:18:43 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 09:20:50 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsint(unsigned int num)
{
	char	c;

	if (num >= 10)
	{
		put_unsint(num / 10);
	}
	c = (num % 10) + '0';
	write(1, &c, 1);
}

int	print_unsigned(unsigned int num)
{
	int	count;

	count = unsigned_len(num);
	put_unsint(num);
	return (count);
}
