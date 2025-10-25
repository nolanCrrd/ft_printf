/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:42:34 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/25 09:44:23 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'u' || c == 'i'
		|| c == 'x' || c == '%' || c == 'X' || c == 'p' || c == 'd');
}

void	print_correct_format(const char	*fmt, va_list *arg, long *nb_write)
{
	char	*buffer;
	char	tmp;

	if (*fmt != 'c' && *fmt != '%')
	{
		if (*fmt == 's')
			buffer = get_str_or_null(va_arg(*arg, char *));
		else if (*fmt == 'i' || *fmt == 'd')
			buffer = ft_lltoa(va_arg(*arg, int));
		else if (*fmt == 'u')
			buffer = ft_ulltoa(va_arg(*arg, unsigned int));
		else if (*fmt == 'x' || *fmt == 'X')
			buffer = ft_xtoa(va_arg(*arg, unsigned int), *fmt == 'X');
		else if (*fmt == 'p')
			buffer = ft_addtoa(va_arg(*arg, unsigned long long));
		*nb_write = write(1, buffer, ft_strlen(buffer));
	}
	else if (*fmt == '%')
		*nb_write = write(1, "%", 1);
	else
	{
		tmp = va_arg(*arg, int);
		*nb_write = write(1, &tmp, 1);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	long	wrote_number;
	long	current_write;

	va_start(arg, fmt);
	wrote_number = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (is_valid_format(*fmt))
				print_correct_format(fmt, &arg, &current_write);
			else
				current_write = ft_printf("%%%c", *fmt);
		}
		else
			current_write = write(1, fmt, 1);
		if (current_write < 0)
			return (E_WRITING_ERR);
		wrote_number += current_write;
		fmt++;
	}
	va_end(arg);
	return (wrote_number);
}
