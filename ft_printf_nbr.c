/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:50 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 22:22:06 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnbr_long(signed long int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int			find_leng_d(size_t d)
{
	ssize_t number;

	number = d;
	if (number <= -2147483647)
		g_l_value++;
	g_l_value = 0;
	if (number <= 0)
	{
		number *= -1;
		g_l_value = 1;
	}
	while (number > 0)
	{
		number /= 10;
		g_l_value++;
	}
	return (g_l_value);
}

int			find_leng_zero(int num)
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
	while (g_leng_zero-- > 0)
		ft_putchar('0');
	return (num);
}

int			find_leng_space_and_zero(int num)
{
	if (!g_w)
		g_leng_space = g_prec - g_leng_d;
	g_leng_space = g_w - g_prec;
	if (num < 0)
		g_leng_space--;
	while (g_leng_space-- > 0)
		ft_putchar(' ');
	g_leng_zero = g_prec - g_leng_d;
	if (num < 0)
		ft_putchar('-');
	if (num == 0 && g_z == 0)
		g_leng_zero++;
	while (g_leng_zero-- > 0)
		ft_putchar('0');
	return (num);
}

void		ft_printf_nbr(va_list *g_my_list)
{
	int num;

	num = va_arg(*g_my_list, int);
	g_leng_zero = 0;
	g_leng_space = 0;
	g_h = num;
	g_leng_d = find_leng_d(num);
	if (g_p > 0)
	{
		if (g_prec >= 0)
			print_space(num);
	}
	else if (g_w)
	{
		if (g_w >= find_leng_d(num))
			g_srccomplet = g_w - find_leng_d(num);
	}
	if (g_z >= 1 && g_m == 0)
		print_mines_and_space(num);
	else if (g_m >= 1)
		find_leng_space_and_check_mines(num);
	else
		print_space_and_num(num);
}
