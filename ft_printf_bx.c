/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:50:54 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 23:44:06 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	find_leng_zero_spac_and_print_bx(unsigned int num)
{
	if ((num < 0) && (g_z == 1) && (g_leng_zero >= 0))
	{
		if (g_length_hex > g_prec)
			ft_putchar('-');
	}
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
		ft_putnbr_base(num, "0123456789ABCDEF");
	return (num);
}

unsigned int	calculat_space_and_print_it_bx(unsigned int num)
{
	if (!(num == 0) || (!g_p))
	{
		ft_putnbr_base(num, "0123456789ABCDEF");
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
		ft_putnbr_base(num, "0123456789ABCDEF");
	else if (num == 0 && g_m == 1 && g_p == 1 && g_w == 0)
		ft_putnbr_base(num, "0123456789ABCDEF");
	return (num);
}

unsigned int	print_bx(unsigned int num)
{
	while (g_srccomplet-- != 0)
		ft_putchar(' ');
	if (num < 0 && g_prec >= g_length_hex)
		ft_putnbr_base(num, "0123456789ABCDEF");
	else if (num != 0 && g_prec >= 0)
		ft_putnbr_base(num, "0123456789ABCDEF");
	else if (num == 0 && g_p == 0)
		ft_putnbr_base(num, "0123456789ABCDEF");
	return (num);
}

void	ft_printf_bx(va_list *g_my_list)
{
	unsigned int	num;

	num = va_arg(*g_my_list, int);
	find_length_hexa(num);
	g_leng_space = 0;
	print_zero(num);
	if (g_z >= 1 && g_m == 0)
		find_leng_zero_spac_and_print_bx(num);
	else if (g_m >= 1)
	{
		print_zero_and_space_x(num);
		calculat_space_and_print_it_bx(num);
		if (g_w > g_prec)
			print_space_x(num);
	}
	else
		print_bx(num);
}
