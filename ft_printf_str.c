/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:34 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 01:42:02 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_leng_space_str(void)
{
	if (g_w > 0 && g_prec == 0 && g_nul != NULL)
	{
		if (!(g_w > g_leng_str && g_p == 0))
			g_leng_prec = g_w;
	}
	else if (g_prec > g_leng_str || g_w > g_leng_str)
		g_leng_prec = g_w - g_leng_str;
	else
		g_leng_prec = g_w - g_prec;
	if (g_prec < g_leng_str)
	{
		if (g_w > g_leng_str && g_prec == 0 && !g_p)
			g_leng_prec = g_w - g_leng_str;
		else
			g_leng_prec = g_w - g_prec;
	}
}

void	print_space_str(char *src)
{
	if (g_w > g_leng_str)
	{
		if (g_nul == NULL && g_w > 0 && g_prec > 0 && g_w > g_prec
			&& g_w > g_leng_str)
			g_leng_prec = g_w - g_prec;
		else if (g_nul == NULL && g_w < g_leng_str)
			g_leng_prec = g_w;
		else if (g_nul == NULL && g_w > g_leng_str && !g_p)
			g_leng_prec = g_w - ft_strlen(src);
		else if (g_nul == NULL)
			g_leng_prec = g_w;
		while (g_leng_prec-- > 0)
			ft_putchar(' ');
	}
	else if (g_p && g_leng_str >= g_w)
	{
		while (g_leng_prec-- > 0)
			ft_putchar(' ');
	}
}

void	wene_with_exist(char *src, int i)
{
	if (g_w)
	{
		if (g_w > 0 && g_prec == 0)
		{
			if (!(g_w && g_p))
			{
				if ((g_nul != NULL || !g_p))
					ft_putstr(src);
			}
			else if (g_w > 0 && g_w > g_leng_str && g_p == 0)
				ft_putstr(src);
		}
		else
		{
			while (g_leng_prec-- > 0 && src[i])
				ft_putchar(src[i++]);
		}
	}
}

void	when_prec_is_bigger_than_with(char *src, int i)
{
	if (g_w < g_leng_str)
	{
		if (g_leng_str > g_prec)
			g_leng_str = g_prec;
		while (g_leng_str-- > 0 && src[i])
			ft_putchar(src[i++]);
	}
	else if (g_leng_str == 1 || g_leng_str == 0)
	{
		g_srccomplet = g_w;
		while (g_srccomplet-- > 0)
			ft_putchar(' ');
	}
	else
	{
		if (g_w > g_leng_str)
		{
			g_srccomplet = g_w - g_leng_str;
			while (g_srccomplet-- > 0)
				ft_putchar(' ');
			while (g_leng_str-- > 0 && src[i])
				ft_putchar(src[i++]);
		}
	}
}

void	ft_printf_str(va_list *g_my_list)
{
	int		i;
	char	*src;

	i = 0;
	src = va_arg(*g_my_list, char *);
	g_nul = src;
	if (src == NULL)
		src = "(null)";
	g_leng_str = ft_strlen(src);
	if (g_w > 0 && g_m == 0 && g_z == 0)
		calculate_leng_space(src, i);
	else
	{
		calculat_leng_str(src);
		if (g_z > 0 && g_m == 0)
			print_zero_and_str(src);
		else if (g_m > 0)
			when_there_is_a_mines(src, i);
		else
			print_str(src, i);
		if (!g_p && !g_w && g_m == 0)
			ft_putstr(src);
	}
}
