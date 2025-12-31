/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:25:46 by amufleh           #+#    #+#             */
/*   Updated: 2025/09/02 19:29:51 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	int_len(int num);
int	hex_len(unsigned int num);
int	print_hex(unsigned long num, char format);
int	print_ptr(unsigned long ptr);
int	print_int(int num);
int	print_unsigned(unsigned int num);
int	unsigned_len(unsigned int num);

#endif
