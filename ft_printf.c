/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:42:34 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/23 14:44:09 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	print_correct_format(const char	*fmt, va_list *arg, size_t *nb_write)
{
	char	*buffer;

	buffer = NULL;
	if (*fmt != 'c' && *fmt != '%')
	{
		if (*fmt == 's')
			buffer = get_str_or_null(va_arg(*arg, char *));
		else if (*fmt == 'i' || *fmt == 'd')
			buffer = ft_lltoa(va_arg(*arg, int));
		else if (*fmt == 'u')
			buffer = ft_ulltoa(va_arg(*arg, unsigned int));
		else if (*fmt == 'x' || *fmt == 'X')
			buffer = ft_ullxtoa(va_arg(*arg, unsigned long long), *fmt == 'X');
		else if (*fmt == 'p')
			buffer = ft_addtoa(va_arg(*arg, unsigned long long));
		*nb_write = write(1, buffer, ft_strlen(buffer));
	}
	else
		*nb_write = write(1, fmt, 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	size_t	wrote_number;
	size_t	current_write;

	va_start(arg, fmt);
	wrote_number = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			print_correct_format(fmt, &arg, &current_write);
		}
		else
			current_write = write(1, fmt, 1);
		if (current_write <= 0)
			return (E_WRITING_ERR);
		wrote_number += current_write;
		fmt++;
	}
	va_end(arg);
	return (wrote_number);
}
