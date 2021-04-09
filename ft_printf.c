/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:42 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/09 23:50:41 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findindex(char *tab, char element)
{
	int	index;

	index = 0;
	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

void	find_star_with(const char *src)
{
	if (src[g_i] == '*' )
	{
		g_w = va_arg(g_my_list, int);
		if (g_w < 0)
		{
			g_m = 1;
			g_w *= -1;
		}
	}
	else
		g_w = ft_atoi(src);
}

void	find_star_prec(const char *src)
{
	if (src[g_i] == '*' )
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
		g_prec = ft_atoi(src);
		if (g_prec < 0)
		{
			g_m = 1;
			g_prec *= -1;
		}
	}
}

void	find_flags(const char *src)
{
	while (src[g_i])
	{
		find_flag_with_prec(src);
		if (g_continu == 0)
		{
			if (g_tempindex != -1)
			{
				(*g_tabfunction[g_tempindex])(&g_my_list);
				return ;
			}
			else
			{
				if (src[g_i] == '%')
				{
					find_percent(src);
					return ;
				}
				else if (src[g_i - 1] == '%' && src[g_i + 1] != '%')
					find_flags_and_percent(src);
				g_i++;
			}
		}
	}
}

int	ft_printf(const char *src, ...)
{	
	int	a;

	va_start(g_my_list, src);
	a = ft_strlen(src);
	g_tempindex = 0;
	g_i = 0;
	g_cont = 0;
	while (src[g_i] != '\0' && g_i < a)
	{
		if (g_i != 0 && src[g_i - 1] == '%')
		{
			init_zero();
			find_flags(src);
		}
		else if (src[g_i] != '%' )
			ft_putchar(src[g_i]);
		g_i++;
	}
	return (g_cont);
}
