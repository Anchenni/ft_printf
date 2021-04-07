/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:42 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 00:46:21 by anchenni         ###   ########.fr       */
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
		// printf("\nsrc de i = %c and g_i de = %d\n", src[g_i], g_i);
		tempindex = findindex(tabindex, src[g_i]);
		if (src[g_i] == '-')
		{
			
			g_m = 1;
			g_i++;
		}
		else if (src[g_i] == '0' && g_z == 0)
		{
			g_z = 1;
			g_i++;
		}
		else if (((src[g_i] <= '9' && src[g_i] >= '0') && (src[g_i] > '0')) || ((src[g_i] == '*')  ))
		{
			find_star_with(src);
			// printf("\ng_w = %d\n", g_w);
			g_i++;
		}
		else if (src[g_i] == '.' && g_p == 0)
		{
			g_p = 1;
			g_i++;

			if (((src[g_i] <= '9' && src[g_i] >= '0')) || ((src[g_i] == '*') ))
			{

				find_star_prec(src);
				
				// printf("\ng_prec = %d\n", g_prec);
				g_i++;
			}
			
		}
		else if (tempindex != -1)
		{
				(*g_tabfunction[tempindex])(&g_my_list);
				return;
		}
		else{ 
			
			// 	return ;
			if (src[g_i] == '%'){
				find_percent(src);
				// g_i++;
				return ;
			}
			else if (src[g_i - 1] == '%' && src[g_i + 1] != '%'){
				ft_putchar(src[g_i]);
				return ;
			}
			// else if(tempindex != -1)
			// 	ft_putchar(src[g_i]);
	// else if (src[g_i] != '%' && src[g_i - 1] == '%')
	// 	ft_putchar(src[g_i]);
	// else if (src[g_i] != '%' && src[g_i - 1] == '%') 
			// else if (src[g_i] != '%') 
			// 	ft_putchar(src[g_i]);	
			g_i++;
		}
	}
}

// void	find_flags(const char *src)
// {
// 	while (src[g_i] == '0' && src[g_i++])
// 		g_z = 1;
// 	while (src[g_i] == '-' && src[g_i++])
// 		g_m += 1;
// 	find_star_with(src);
// 	while (src[g_i] <= '9' && src[g_i] >= '0')
// 		g_i++;
// 	while (src[g_i] == '-' && src[g_i++])
// 		g_m += 1;
// 	if (src[g_i] == '.' && src[g_i++])
// 		g_p += 1;
// 	find_star_prec(src);
// 	while (src[g_i] == '-' && src[g_i++])
// 		g_m += 1;
// 	while (src[g_i] <= '9' && src[g_i] >= '0')
// 		g_i++;
// }

int	ft_printf(const char *src, ...)
{
	// static char	tabindex[8] = {'s', 'c', 'd', 'i', 'u', 'x', 'X', 'p'};
	// int			tempindex;

	tempindex = 0;
	g_i = 0;
	g_cont = 0;
	va_start(g_my_list, src);
	int a = ft_strlen(src);
	while (src[g_i] != '\0' && g_i < a)
	{
		if (g_i != 0 && src[g_i - 1] == '%')
		{
			init_zero();
			// printf("\nOk1\n");
			find_flags(src);
			// tempindex = findindex(tabindex, src[g_i]);
			// if (tempindex != -1)
			// 	(*g_tabfunction[tempindex])(&g_my_list);
			// else
			// 	find_percent(src);
			// printf("\nOk2\n");
			// printf("\n 1: g_i = %d src de i = %c\n", g_i, src[g_i]);

		}
		else if (src[g_i] != '%' ){
			// printf("g_i = %d src de i = %c\n", g_i, src[g_i]);
			ft_putchar(src[g_i]);
			
		}
		
		g_i++;
	}
	

	return (g_cont);
}
