/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:02:20 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 01:24:18 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	calculat_space_p(size_t num)
{
	if (num == 0)
	{
		ft_decimal_tohexa(num);
		g_srccomplet -= 1;
	}
	find_length_hexa(num);
	if (!(num == 0))
	{
		if (g_w == 0)
			g_srccomplet = 0;
		else
			g_srccomplet = g_w - g_length_hex - 2;
	}
	if (!g_w)
	{
		while (g_srccomplet-- != 0)
			ft_putchar(' ');
		if (num != 0)
			ft_decimal_tohexa(num);
	}
	return (num);
}

size_t	when_there_is_a_mines_p(size_t num)
{
	ft_putstr("0x");
	if (num == 0 && g_prec > 0)
		g_srccomplet++;
	else if (g_p == 0)
		ft_decimal_tohexa(num);
	if (g_w < g_length_hex)
		calculat_space_p(num);
	else
	{
		find_length_hexa(num);
		if (g_w > g_length_hex)
		{
			if (g_p && num == 0)
				g_srccomplet = g_w - 2;
			else
				g_srccomplet = g_w - g_length_hex - 2;
			if (g_srccomplet < 0)
				g_srccomplet = 0;
			while (g_srccomplet-- != 0)
				ft_putchar(' ');
		}
	}
	return (num);
}

size_t	whene_there_is_no_mines_p(size_t num)
{
	if (num == 0 && g_prec == 0 && g_w)
	{
		g_srccomplet = g_w - 2;
		if (num == 0 && g_p == 0)
			g_srccomplet--;
	}
	if (g_length_hex < g_w)
	{
		if (num == 0 && g_w < g_length_hex)
			g_srccomplet++;
		while (g_srccomplet-- != 0)
			ft_putchar(' ');
	}
	ft_putstr("0x");
	if(g_prec > g_w && g_prec > g_length_hex)
	{
		g_leng_space = g_prec - find_leng_d(num) + 1;
		while (g_leng_space-- != 0)
			ft_putchar('0');

	}
	if (num != 0 && g_prec >= 0)
		ft_decimal_tohexa(num);
	else if (num == 0 && g_p == 0)
		ft_decimal_tohexa(num);
	return (num);
}
