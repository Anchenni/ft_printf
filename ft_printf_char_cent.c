/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_cent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:51:23 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/03 19:52:42 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		find_lengzero_and_lengspace_and_print_char(char src)
{
	if (g_w)
	{
		if (g_w >= 1)
			g_srccomplet = g_w - 1;
	}
	if (g_z >= 1 && g_m == 0)
		print_space_char(src);
	else if (g_m >= 1)
	{
		ft_putchar(src);
		while (g_srccomplet-- != 0)
			ft_putchar(' ');
	}
	else
	{
		while (g_srccomplet-- != 0)
			ft_putchar(' ');
		ft_putchar(src);
	}
}

void		ft_printf_char_cent(void)
{
	char src;

	g_srccomplet = 0;
	src = '%';
	if (g_w > 0 && g_z == 0)
	{
		g_w--;
		if (g_m > 0)
			ft_putchar(src);
		while (g_w-- != 0)
			ft_putchar(' ');
		if (g_m <= 0)
			ft_putchar(src);
	}
	else if (g_p > 0 && g_z == 0)
		ft_putchar(src);
	else
		find_lengzero_and_lengspace_and_print_char(src);
}
