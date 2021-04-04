/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:53:30 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 22:21:47 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_space_char(char src)
{
	while (g_srccomplet-- != 0)
		ft_putchar('0');
	ft_putchar(src);
}

void		print_char_and_space_and_zero(char src)
{
	if (g_w)
	{
		if (g_w >= 1)
			g_srccomplet = g_w - 1;
	}
	if (g_z >= 1)
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

void		ft_printf_char(va_list *g_my_list)
{
	char src;

	src = va_arg(*g_my_list, int);
	g_srccomplet = 0;
	if (g_w > 0)
	{
		g_w--;
		if (g_m > 0)
			ft_putchar(src);
		while (g_w-- != 0)
			ft_putchar(' ');
		if (g_m <= 0)
			ft_putchar(src);
	}
	else if (g_p > 0)
		ft_putchar(src);
	else
		print_char_and_space_and_zero(src);
}
