/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:36:43 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/01 17:27:46 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	if (!str)
	{
		print_str("(null)");
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd (str, 1);
	return (ft_strlen(str));
}
