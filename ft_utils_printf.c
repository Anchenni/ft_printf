/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:02:32 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/03 20:02:35 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		init_zero(void)
{
	g_w = 0;
	g_z = 0;
	g_l_value = 0;
	g_prec = 0;
	g_p = 0;
	g_length_hex = 0;
	g_m = 0;
	g_compt = 0;
	g_cont = 0;
	g_space = 0;
	g_prec_neg = 0;
	g_j = 0;
	g_srccomplet = 0;
	g_leng_d = 0;
	g_leng_prec = 0;
}

void		find_percent(const char *src)
{
	if (src[g_i] == '%')
	{
		g_j++;
		if (g_j % 1 == 0)
			ft_printf_char_cent();
		if (src[g_i + 1])
			g_i++;
		if (src[g_i] != '%')
			ft_putchar(src[g_i]);
	}
	else
		ft_putchar(src[g_i]);
}
