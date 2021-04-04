/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:59:50 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 22:22:30 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_putnbr_u(unsigned int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		ft_putnbr_u(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
}

unsigned int	print_space_and_num_u(unsigned int num)
{
	calculate_leng_zero2_u(num);
	if (!(num == 0) || (!g_p))
	{
		ft_putnbr_u(num);
		if (g_prec_neg > 0 && g_z == 0)
		{
			if (g_prec < g_w && g_m > 0)
				g_leng_space = g_prec - g_leng_d;
			else
				g_leng_space = g_w - g_leng_d;
			while (g_leng_space-- > 0)
				ft_putchar(' ');
		}
	}
	if (g_prec > 0 && g_w && num == 0)
		ft_putnbr_u(num);
	else if (num == 0 && g_m == 1 && g_p == 1 && g_w == 0)
		ft_putnbr_u(num);
	calculat_leng_space2_u(num);
	return (num);
}

unsigned int	print_u(unsigned int num)
{
	while (g_srccomplet-- != 0)
		ft_putchar(' ');
	if (num < 0 && g_prec >= g_leng_d)
		ft_putnbr_u(num);
	else if (num != 0 && g_prec >= 0)
		ft_putnbr_u(num);
	else if (num == 0 && g_p == 0)
		ft_putnbr_u(num);
	return (num);
}

unsigned int	print_mines_and_zero_u(unsigned int num)
{
	if ((num < 0) && (g_z == 1) && (g_leng_zero >= 0))
	{
		if (g_leng_d > g_prec)
			ft_putchar('-');
	}
	while (g_srccomplet-- != 0)
		ft_putchar('0');
	ft_putnbr_u(num);
	return (num);
}

void			ft_printf_u(va_list *g_my_list)
{
	unsigned int num;

	num = va_arg(*g_my_list, int);
	g_leng_d = find_leng_d(num);
	if (g_p > 0)
		print_space_u(num);
	else if (g_w)
	{
		if (g_w >= find_leng_d(num))
			g_srccomplet = g_w - find_leng_d(num);
	}
	if (g_z >= 1 && g_m == 0)
		print_mines_and_zero_u(num);
	else if (g_m >= 1)
		print_space_and_num_u(num);
	else
		print_u(num);
}
