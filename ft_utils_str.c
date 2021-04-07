/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:02:54 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 01:42:34 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	when_there_is_a_mines(char *src, int i)
{
	if (g_p && g_prec < g_leng_str && g_prec > g_w)
	{
		if (g_leng_str < g_prec)
		{
			while (g_prec-- != 0)
				ft_putchar(src[i++]);
		}
		else
			ft_putstr(src);
		if (g_w > 0)
			g_srccomplet = g_leng_str - g_prec;
		while (g_srccomplet-- > 0)
			ft_putchar(' ');
	}
	else
		calculate_spac_and_print_str(src, i);
	if (g_w > g_leng_str && g_prec_neg == 0)
	{
		while (g_srccomplet-- > 0)
			ft_putchar(' ');
	}
}

void	calculate_leng_space(char *src, int i)
{
	if (g_w >= g_prec)
	{
		find_leng_space_str();
		print_space_str(src);
		if (g_prec > g_leng_str)
			g_leng_prec = g_leng_str;
		else if (g_w > g_leng_str && g_p == 0)
			g_leng_prec = g_w - g_leng_str;
		else
			g_leng_prec = g_prec;
		wene_with_exist(src, i);
	}
	else
		when_prec_is_bigger_than_with(src, i);
}

void	calculat_leng_str(char *src)
{
	int	m;

	if (g_w)
	{
		m = ft_strlen(src);
		if (g_w >= m)
			g_srccomplet = g_w - ft_strlen(src);
		else
			g_srccomplet = g_leng_str;
	}
}

void	print_str(char *src, int i)
{
	if (g_prec > g_leng_str)
		g_leng_prec = g_leng_str;
	else
		g_leng_prec = g_prec;
	while (g_leng_prec-- > 0)
		ft_putchar(src[i++]);
}

void	print_zero_and_str(char *src)
{
	if( g_w > g_leng_str){
		while (g_srccomplet-- > 0)
			ft_putchar('0');
	}
	if(g_w != 0 )
	ft_putstr(src);
}
