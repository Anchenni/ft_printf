/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:29 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 23:45:44 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	print_zero_and_space_x(unsigned int num)
{
	if (g_prec > 0 && g_length_hex < g_prec)
	{
		g_leng_zero = g_prec - g_length_hex;
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

unsigned int	print_x(unsigned int num)
{
	while (g_srccomplet-- != 0)
		ft_putchar(' ');
	if (num < 0 && g_prec >= g_length_hex)
		ft_putnbr_base(num, "0123456789abcdef");
	else if (num != 0 && g_prec >= 0)
		ft_putnbr_base(num, "0123456789abcdef");
	else if (num == 0 && g_p == 0)
		ft_putnbr_base(num, "0123456789abcdef");
	return (num);
}

unsigned int	calculat_space_and_print_it_x(unsigned int num)
{
	if (!(num == 0) || (!g_p))
	{
		ft_putnbr_base(num, "0123456789abcdef");
		if (g_prec_neg > 0 && g_z == 0)
		{
			if (g_prec < g_w && g_m > 0)
				g_leng_space = g_prec - g_length_hex;
			else
				g_leng_space = g_w - g_length_hex;
			while (g_leng_space-- > 0)
				ft_putchar(' ');
		}
	}
	else if (g_prec > 0 && g_w && num == 0)
		ft_putnbr_base(num, "0123456789abcdef");
	else if (num == 0 && g_m == 1 && g_p == 1 && g_w == 0)
		ft_putnbr_base(num, "0123456789abcdef");
	return (num);
}

unsigned int	calc_leng_spac2_x(unsigned int num)
{
	if (g_w > g_length_hex && g_prec > 0)
	{
		g_leng_space = g_w - g_prec;
		if (g_prec < g_length_hex)
			g_leng_space--;
	}
	else if (g_w > g_length_hex && g_prec)
		g_leng_space = g_w - g_length_hex;
	else if ((g_w > 0 && !g_p) && g_length_hex < g_w)
		g_leng_space = g_w - g_length_hex;
	else
		g_leng_space = 0;
	return (num);
}

unsigned int	print_space_x(unsigned int num)
{
	calc_leng_spac2_x(num);
	if (num < 0 && g_prec)
	{
		g_leng_space--;
		if (g_w > g_length_hex && g_prec < g_length_hex)
			g_leng_space = g_length_hex - 1;
	}
	if (g_m == 1 && g_length_hex < g_w && g_p && g_prec == 0 && num != 0)
		g_leng_space = g_w - g_length_hex;
	if (num == 0 && g_prec == 0 && g_m > 0)
	{
		g_leng_space = g_w;
		if (g_p == 0)
			g_leng_space--;
	}
	while (g_leng_space-- != 0)
		ft_putchar(' ');
	return (num);
}
