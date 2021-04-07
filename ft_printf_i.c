/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:54:37 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/05 21:55:16 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(va_list *g_my_list)
{
	int	num;
	
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
