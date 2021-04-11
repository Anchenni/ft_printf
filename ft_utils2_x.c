/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:12:49 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/11 16:19:54 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	find_leng_zero_spac_and_print_x(unsigned int num)
{
	calculat_leng_zero(num);
	if (g_prec > 0 && g_w > 0 && g_prec < g_w && g_prec > g_length_hex)
		g_leng_space = g_w - g_prec;
	else if (g_p && g_w && g_w > g_prec)
		g_leng_space = g_w - g_length_hex;
	while (g_leng_space-- != 0)
		ft_putchar(' ');
	if (g_prec == 0 && g_w < g_length_hex && !g_p)
		g_leng_zero = 0;
	else if (g_prec > 0 && g_prec < g_length_hex && g_w > 0)
		g_leng_zero = 0;
	while (g_leng_zero-- != 0)
		ft_putchar('0');
	if (!(num == 0) || (!g_p))
		ft_putnbr_base(num, "0123456789abcdef");
	return (num);
}

unsigned int	print_zero(unsigned int num)
{
	if (g_p > 0 && g_m == 0 && g_z == 0)
	{
		if ((g_prec) || (g_w))
		{
			if (g_prec >= g_w && g_length_hex < g_prec)
			{
				g_leng_zero = g_prec - g_length_hex;
				if (num == 0)
					g_leng_zero++;
				while (g_leng_zero-- != 0)
					ft_putchar('0');
			}
			else if (g_w >= g_prec)
				claculat_space_and_zero_and_print_it(num);
		}
	}
	else if (g_w && g_m == 0 && g_z == 0)
	{
		if (g_w >= g_length_hex)
			g_srccomplet = g_w - g_length_hex;
	}
	return (num);
}
