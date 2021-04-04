/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:01:36 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/03 20:01:58 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_mines_and_space(int num)
{
	if ((num < 0) && (g_z == 1) && (g_leng_zero >= 0))
	{
		if (g_leng_d > g_prec)
			ft_putchar('-');
	}
	while (g_srccomplet-- > 0)
		ft_putchar('0');
	if (num == 0 && g_prec == 0 && g_p == 0 && g_w == 0)
		ft_putnbr_long(g_h);
	else if (g_w > 0 || num != 0)
		ft_putnbr_long(g_h);
	return (num);
}

int			find_leng_space_when_with_bigger_than_prec(int num)
{
	if (g_w > g_leng_d && g_prec > 0)
	{
		g_leng_space = g_w - g_prec;
		if (g_prec < g_leng_d)
			g_leng_space--;
	}
	else if (g_w > g_leng_d && g_prec)
		g_leng_space = g_w - g_leng_d;
	else if ((g_w > 0 && !g_p) && g_leng_d < g_w)
		g_leng_space = g_w - g_leng_d;
	else
		g_leng_space = 0;
	print_space_nbr(num);
	if (g_m == 1 && g_leng_d < g_w && g_p && g_prec == 0)
		g_leng_space = g_w - g_prec;
	if (g_leng_d > g_prec && num < 0 && g_w > g_leng_d && g_p > 0)
		g_leng_space = g_w - g_leng_d - 1;
	if (g_m > 0 && g_w > g_leng_d && g_leng_d > g_prec && g_p > 0 && num > 0)
		g_leng_space = g_w - g_leng_d;
	while (g_leng_space-- > 0)
		ft_putchar(' ');
	return (num);
}

int			print_space_when_num_diff_than_zero(int num)
{
	ft_putnbr_long(g_h);
	if (g_prec_neg > 0 && g_z == 0)
	{
		if (g_prec < g_w && g_m > 0)
			g_leng_space = g_prec - g_leng_d;
		else
			g_leng_space = g_w - g_leng_d;
		while (g_leng_space-- > 0)
			ft_putchar(' ');
	}
	return (num);
}

int			print_space_and_num(int num)
{
	while (g_srccomplet-- > 0)
		ft_putchar(' ');
	if (num < 0 && g_prec >= g_leng_d)
		ft_putnbr_long(g_h);
	else if (num != 0 && g_prec >= 0)
		ft_putnbr(num);
	else if (num == 0 && g_p == 0)
		ft_putnbr(num);
	return (num);
}

int			find_leng_space_and_check_mines(int num)
{
	if (g_prec > 0 && g_leng_d < g_prec)
		print_mines_and_zero(num);
	else
	{
		if (num < 0)
			ft_putchar('-');
	}
	if (!(num == 0) || (!g_p))
		print_space_when_num_diff_than_zero(num);
	if (g_prec > 0 && g_w && num == 0)
		ft_putnbr_long(g_h);
	else if (num == 0 && g_m == 1 && g_p == 1 && g_w == 0)
		ft_putnbr_long(g_h);
	if (g_w > g_prec)
		find_leng_space_when_with_bigger_than_prec(num);
	return (num);
}
