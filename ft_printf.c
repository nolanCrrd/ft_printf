/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:50:46 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/22 13:52:51 ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>


int ft_printf(const char *fmt, ...)
{
	va_list arg;
	size_t	wrote_number;
	size_t	current_write;
	char	*buffer;
	char	tmp;

	va_start(arg, fmt);
	wrote_number = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
				current_write = ft_putstr(va_arg(arg, char *));
			else if (*fmt == 'c')
			{
				tmp = va_arg(arg, int);
				current_write = write(1, &tmp, 1);
			}
			else if (*fmt == 'i' || *fmt == 'd')
			{
				buffer = ft_lltoa(va_arg(arg, int));
				current_write = write(1, buffer, ft_strlen(buffer));
			}
			else if (*fmt == 'u')
			{
				buffer = ft_ulltoa(va_arg(arg,unsigned int));
				current_write = write(1, buffer, ft_strlen(buffer));
			}
			else if (*fmt == '%')
				current_write = write(1, "%", 1);
			else if (*fmt == 'x')
			{
				buffer = ft_ullxtoa(va_arg(arg, unsigned long long), 0);
				current_write = write(1, buffer, ft_strlen(buffer));
			}
			else if (*fmt == 'X')
			{
				buffer = ft_ullxtoa(va_arg(arg, unsigned long long), 1);
				current_write = write(1, buffer, ft_strlen(buffer));
			}
			else if (*fmt == 'p')
			{
				buffer = ft_addtoa(va_arg(arg, unsigned long long));
				current_write = write(1, buffer, ft_strlen(buffer));
			}
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
