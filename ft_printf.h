/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:26:03 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/22 12:48:42y ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stddef.h>

enum	e_err_code
{
	E_SUCCESS = 0,
	E_WRITING_ERR = -1,
	E_NULL = -2,
};

__attribute__((format(printf, 1, 2)))
int	ft_printf(const char *fmt, ...);
int	ft_putstr(char *str);
size_t	ft_strlen(char *str);
void	ft_bzero(void *ptr, size_t len);
char	*ft_lltoa(long long nbr);
char	*ft_ulltoa(unsigned long long nbr);
char	*ft_ullxtoa(unsigned long long nbr, int is_upper);
char	*ft_addtoa(unsigned long long addr);

#endif