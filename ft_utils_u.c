/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:03:21 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/09 23:42:37 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	calculat_leng_zero_u(unsigned int num)
{
	if (!(num < 0 && g_leng_d > g_prec))
		g_leng_zero = g_prec - g_leng_d;
	if (num < 0)
	{
		ft_putchar('-');
		g_leng_zero++;
	}
	if (num == 0)
		g_leng_zero++;
	if (num < 0)
		g_leng_zero--;
	while (g_leng_zero-- != 0)
		ft_putchar('0');
	return (num);
}

unsigned int	calculate_leng_zero2_u(unsigned int num)
{
	if (g_prec > 0 && g_leng_d < g_prec)
	{
		if (g_w > 0 && g_w < g_prec && g_leng_d < g_w
			&& g_leng_d < g_prec && g_prec > 0
			&& g_w < g_prec && g_z > 0)
			g_leng_zero = g_w - g_leng_d;
		else
			g_leng_zero = g_prec - g_leng_d;
		if (num < 0)
			ft_putchar('-');
		if (g_prec_neg == 0 || g_z > 0)
		{
			while (g_leng_zero-- != 0)
				ft_putchar('0');
		}
	}
	else
	{
		if (num < 0)
			ft_putchar('-');
	}
	return (num);
}

unsigned int	print_spac_mines_and_zero_u(unsigned int num)
{
	if (!g_w)
		g_leng_space = g_prec - g_leng_d;
	g_leng_space = g_w - g_prec;
	if (num < 0)
		g_leng_space--;
	while (g_leng_space-- != 0)
		ft_putchar(' ');
	g_leng_zero = g_prec - g_leng_d;
	if (num < 0)
		ft_putchar('-');
	if (num == 0 && g_z == 0)
		g_leng_zero++;
	while (g_leng_zero-- != 0)
		ft_putchar('0');
	return (num);
}

unsigned int	calculat_leng_space2_u(unsigned int num)
{
	if (g_w > g_prec)
	{
		if (g_w > g_leng_d && g_prec > 0)
		{
			g_leng_space = g_w - g_prec;
			if (g_prec < g_leng_d)
				g_leng_space--;
		}
		else if ((g_w > g_leng_d && g_prec)
			|| ((g_w > 0 && !g_p) && g_leng_d < g_w))
			g_leng_space = g_w - g_leng_d;
		else
			g_leng_space = 0;
		if (num < 0 && g_prec)
		{
			g_leng_space--;
			if (g_w > g_leng_d && g_prec < g_leng_d)
				g_leng_space = g_leng_d - 1;
		}
		calculate_space_u(num);
		while (g_leng_space-- != 0)
			ft_putchar(' ');
	}
	return (num);
}

unsigned int	print_space_u(unsigned int num)
{
	if (g_prec >= 0)
	{
		if (num < 0)
			g_leng_d--;
		if (g_prec >= g_w && g_leng_d <= g_prec && g_m == 0)
			calculat_leng_zero_u(num);
		else if (g_w >= g_prec && g_m == 0)
		{
			if (g_prec > g_leng_d)
				print_spac_mines_and_zero_u(num);
			else
			{
				g_leng_d = find_leng_d(num);
				g_leng_space = g_w - g_leng_d;
				if (num == 0)
					g_leng_space = g_w - g_prec;
				while (g_leng_space-- > 0)
					ft_putchar(' ');
			}
		}
	}
	return (num);
}
