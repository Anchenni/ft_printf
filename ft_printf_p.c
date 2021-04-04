/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:59:11 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 22:22:13 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_decimal_tohexa(size_t n)
{
	g_length_hex = 0;
	if (n > 15)
	{
		ft_decimal_tohexa(n / 16);
		n %= 16;
	}
	if (n > 9)
		ft_putchar(n + 87);
	else
		ft_putchar(n + 48);
}

void		find_length_hexa(size_t n)
{
	if (n > 15)
	{
		find_length_hexa(n / 16);
		n %= 16;
	}
	if (n > 9)
		g_length_hex++;
	else
		g_length_hex++;
}

void		ft_printf_p(va_list *g_my_list)
{
	size_t num;

	num = va_arg(*g_my_list, size_t);
	find_length_hexa(num);
	g_length_hex += 2;
	if (g_w)
	{
		if (g_w >= g_length_hex)
			g_srccomplet = g_w - g_length_hex;
		else
			g_srccomplet = g_w - 2;
	}
	if (g_z >= 1)
	{
		while (g_srccomplet-- != 0)
			ft_putchar('0');
		ft_putstr("0x");
		ft_decimal_tohexa(num);
	}
	else if (g_m >= 1)
		when_there_is_a_mines_p(num);
	else
		whene_there_is_no_mines_p(num);
}
