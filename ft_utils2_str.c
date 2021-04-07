/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:08:36 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 23:45:56 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_leng_str_and_print_space(char *src, int i)
{
	if (g_prec_neg > 0 && g_prec < g_leng_str)
		g_srccomplet = g_leng_str;
	else
		g_srccomplet = g_prec;
	if (g_prec_neg > 0)
		g_srccomplet++;
	while (g_srccomplet-- > 0 && src[i])
		ft_putchar(src[i++]);
	if (g_w > g_prec)
		g_srccomplet = g_w - g_prec;
	if (g_prec_neg == 1)
		g_srccomplet--;
	if (g_prec_neg > 0 && g_prec < g_leng_str)
		g_srccomplet = g_w - g_leng_str;
	while (g_srccomplet-- > 0)
		ft_putchar(' ');
}

void	calculate_spac_and_print_str(char *src, int i)
{
	if (g_w && g_prec < g_leng_str && g_p)
		find_leng_str_and_print_space(src, i);
	else if (g_w > 0)
	{
		if (g_prec_neg > 0 && g_prec > g_leng_str
			&& g_w < g_prec)
		{
			g_srccomplet = g_w - g_leng_str;
			while (g_srccomplet-- > 0)
				ft_putchar(' ');
		}
		ft_putstr(src);
	}
	else if (g_w == 0 && g_prec > 0)
		ft_putstr(src);
	else if (g_w == 0 && g_prec == 0 && !g_p)
		ft_putstr(src);
}
