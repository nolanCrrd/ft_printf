/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:34 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/22 13:34:35by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest strings\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// Strings tests
	assert(ft_printf("test\n") == printf("test\n"));
	printf("========\n");
	assert(ft_printf("%s", "coucou\n") == printf("%s", "coucou\n"));
	printf("========\n");
	assert(ft_printf("%s", "coucou") == printf("%s", "coucou"));
	printf("\n========\n");
	assert(ft_printf("%s", "") == printf("%s", ""));
	printf("\n========\n");
	assert(ft_printf(" %s", "") == printf(" %s", ""));
	printf("\n========\n");
	assert(ft_printf("test : %s : test\n", "coucou") == printf("test : %s : test\n", "coucou"));
	printf("========\n");
	assert(ft_printf("%s", (char *)NULL) == printf("%s", (char *)NULL));
	printf("\n========\n");
	assert(ft_printf("%s", (char *)0) == printf("%s", (char *)0));
	printf("\n========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest char\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests char
	assert(ft_printf("%c", 'c') == printf("%c", 'c'));
	printf("\n========\n");
	assert(ft_printf("test : %c : test\n", 'a') == printf("test : %c : test\n", 'a'));
	printf("========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest int/d\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests char
	assert(ft_printf("%i\n", 0) == printf("%i\n", 0));
	printf("========\n");
	assert(ft_printf("%i\n", 1) == printf("%i\n", 1));
	printf("========\n");
	assert(ft_printf("%i\n", -1) == printf("%i\n", -1));
	printf("========\n");
	assert(ft_printf("%i\n", 10) == printf("%i\n", 10));
	printf("========\n");
	assert(ft_printf("%i\n", -10) == printf("%i\n", -10));
	printf("========\n");
	assert(ft_printf("%i\n", -121312) == printf("%i\n", -121312));
	printf("========\n");
	assert(ft_printf("%i\n", 121312) == printf("%i\n", 121312));
	printf("========\n");
	assert(ft_printf("%i\n", 2147483647) == printf("%i\n", 2147483647));
	printf("========\n");
	assert(ft_printf("%i\n", -2147483647) == printf("%i\n", -2147483647));
	printf("========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest pointer\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests pointer
	char	*ptr = malloc(10);
	assert(ft_printf("%p\n", ptr) == printf("%p\n", ptr));
	printf("========\n");
	assert(ft_printf("%p\n", "coucou") == printf("%p\n", "coucou"));
	printf("========\n");
	assert(ft_printf("%p\n", NULL) == printf("%p\n",NULL));
	printf("========\n");
	free(ptr);

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest mini hex\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests x
	assert(ft_printf("%x\n", 0) == printf("%x\n", 0));
	printf("========\n");
	assert(ft_printf("%x\n", 1) == printf("%x\n", 1));
	printf("========\n");
	assert(ft_printf("%x\n", -1) == printf("%x\n", -1));
	printf("========\n");
	assert(ft_printf("%x\n", 10) == printf("%x\n", 10));
	printf("========\n");
	assert(ft_printf("%x\n", -10) == printf("%x\n", -10));
	printf("========\n");
	assert(ft_printf("%x\n", -121312) == printf("%x\n", -121312));
	printf("========\n");
	assert(ft_printf("%x\n", 121312) == printf("%x\n", 121312));
	printf("========\n");
	assert(ft_printf("%x\n", 2147483647) == printf("%x\n", 2147483647));
	printf("========\n");
	assert(ft_printf("%x\n", -2147483647) == printf("%x\n", -2147483647));
	printf("========\n");
	assert(ft_printf("%x\n", LONG_MAX));
	printf("========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest max hex\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests x
	assert(ft_printf("%X\n", 0) == printf("%X\n", 0));
	printf("========\n");
	assert(ft_printf("%X\n", 1) == printf("%X\n", 1));
	printf("========\n");
	assert(ft_printf("%X\n", -1) == printf("%X\n", -1));
	printf("========\n");
	assert(ft_printf("%X\n", 10) == printf("%X\n", 10));
	printf("========\n");
	assert(ft_printf("%X\n", -10) == printf("%X\n", -10));
	printf("========\n");
	assert(ft_printf("%X\n", -121312) == printf("%X\n", -121312));
	printf("========\n");
	assert(ft_printf("%X\n", 121312) == printf("%X\n", 121312));
	printf("========\n");
	assert(ft_printf("%X\n", 2147483647) == printf("%X\n", 2147483647));
	printf("========\n");
	assert(ft_printf("%X\n", -2147483647) == printf("%X\n", -2147483647));
	printf("========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest %%\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests %
	assert(ft_printf("%%\n") == printf("%%\n"));
	printf("========\n");

	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=\ntest rdm\n=-=-=-=-=-=-=-=-=-=-=-\n\n");
	// tests rdm
	assert(ft_printf("%z\n") == 3);
	printf("========\n");
	assert(ft_printf("test%\n") == 6);
	printf("========\n");
}