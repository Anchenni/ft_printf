/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:42 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/04 22:22:48 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			findindex(char *tab, char element)
{
	int index;

	index = 0;
	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

void		find_star_with(const char *src)
{
	if (src[g_i] == '*' && src[g_i++])
	{
		g_w = va_arg(g_my_list, int);
		if (g_w < 0)
		{
			g_m = 1;
			g_w *= -1;
		}
	}
	else
		g_w = ft_atoi(src + g_i);
}

void		find_star_prec(const char *src)
{
	if (src[g_i] == '*' && src[g_i++])
	{
		g_prec = va_arg(g_my_list, int);
		if (g_prec < 0)
		{
			g_m = 1;
			g_prec_neg = 1;
			g_prec *= -1;
		}
	}
	else
	{
		g_prec = ft_atoi(src + g_i);
		if (g_prec < 0)
		{
			g_m = 1;
			g_prec *= -1;
		}
	}
}

void		find_flags(const char *src)
{
	while (src[g_i] == '0' && src[g_i++])
		g_z = 1;
	while (src[g_i] == '-' && src[g_i++])
		g_m += 1;
	find_star_with(src);
	while (src[g_i] <= '9' && src[g_i] >= '0')
		g_i++;
	while (src[g_i] == '-' && src[g_i++])
		g_m += 1;
	if (src[g_i] == '.' && src[g_i++])
		g_p += 1;
	find_star_prec(src);
	while (src[g_i] == '-' && src[g_i++])
		g_m += 1;
	while (src[g_i] <= '9' && src[g_i] >= '0')
		g_i++;
}

int			ft_printf(const char *src, ...)
{
	static char	tabindex[8] = { 's', 'c', 'd', 'i', 'u', 'x', 'X', 'p'};
	int			tempindex;

	tempindex = 0;
	g_i = 0;
	va_start(g_my_list, src);
	while (src[g_i] != 0)
	{
		if (g_i != 0 && src[g_i - 1] == '%')
		{
			init_zero();
			find_flags(src);
			tempindex = findindex(tabindex, src[g_i]);
			if (tempindex != -1)
				(*g_tabfunction[tempindex])(&g_my_list);
			else
				find_percent(src);
		}
		else if (src[g_i] != '%')
			ft_putchar(src[g_i]);
		g_i++;
	}
	return (g_cont);
}
