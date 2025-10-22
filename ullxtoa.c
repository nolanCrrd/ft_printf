/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ullxtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:40:51 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:20 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addtoa(unsigned long long addr)
{
	static char	buffer[15];
	char		*cursor;
	char		*base;

	if (addr == 0)
		return ("(nil)");
	ft_bzero(buffer, sizeof(buffer));
	cursor = &buffer[13];
	base = "0123456789abcdef";
	while (addr / 16 != 0 )
	{
		*cursor-- = base[addr % 16];
		addr /= 16;
	}
	*cursor-- = base[addr % 16];
	*cursor-- = 'x';
	*cursor = '0';
	return (cursor);
}

char	*ft_ullxtoa(unsigned long long nbr, int is_upper)
{
	static char	buffer[13];
	char		*cursor;
	char		*base;

	ft_bzero(buffer, sizeof(buffer));
	cursor = &buffer[11];
	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
	while (nbr / 16 != 0 )
	{
		*cursor-- = base[nbr % 16];
		nbr /= 16;
	}
	*cursor = base[nbr % 16];
	return (cursor);
}