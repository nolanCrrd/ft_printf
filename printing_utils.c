/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:28:21 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/23 10:33:21 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (size);
	while (*str++)
		size++;
	return (size);
}

void	ft_bzero(void *ptr, size_t len)
{
	unsigned char	*cptr;

	cptr = (unsigned char *) ptr;
	while (len-- > 0)
		cptr[len] = 0;
}

char	*get_str_or_null(char	*str)
{
	if (!str)
		return ("(null)");
	return (str);
}
