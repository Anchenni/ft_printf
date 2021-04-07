/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:08:15 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 01:07:34 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_mines_and_zero(int num)
{
	// printf("\ng_leng_zero = %d\n",g_leng_zero);
	if (g_w == 0 && g_prec > g_leng_d)
		g_leng_zero = 0;
	else {
		g_leng_zero = g_prec - g_leng_d;
	}
	if (num < 0)
		ft_putchar('-');
	if (g_z > 0 && g_w > g_leng_d && num != 0 && g_w < g_prec )
	{
				g_leng_zero = g_w - g_leng_d;
	}
	if (g_prec_neg == 0 || g_z > 0 )
	{
		if (g_prec_neg == 0 && g_m > 0 && g_w == 0 && g_prec > g_leng_d){
			g_leng_zero = g_prec - g_leng_d;
		}
// printf("\ng_w = %d et g_prec = %d et g_prec_neg = %d\n", g_w, g_prec, g_prec_neg);
		while (g_leng_zero-- > 0)
			ft_putchar('0');
	}
	return (num);
}

int	print_space(int num)
{
	if (num < 0)
		g_leng_d--;
	if (g_prec >= g_w && g_leng_d <= g_prec && g_m == 0)
		num = find_leng_zero(num);
	else if (g_w >= g_prec && g_m == 0)
	{
		if (g_prec > g_leng_d)
			find_leng_space_and_zero(num);
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
	return (num);
}

int	print_space_nbr(int num)
{
	if (num < 0 && g_prec)
	{
		g_leng_space--;
		if (g_w > g_leng_d && g_prec < g_leng_d)
			g_leng_space = g_leng_d - 1;
	}
	return (num);
}
