/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:02:32 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/08 00:46:37 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_zero(void)
{
	g_w = 0;
	g_z = 0;
	g_l_value = 0;
	g_prec = 0;
	g_p = 0;
	g_length_hex = 0;
	g_m = 0;
	g_compt = 0;
	g_space = 0;
	g_prec_neg = 0;
	g_j = 0;
	g_srccomplet = 0;
	g_leng_d = 0;
	g_leng_prec = 0;
}

void	find_percent(const char *src)
{
	// if (src[g_i] == '%')
	// {
		g_j++;
		if (g_j % 2 == 1)
			ft_printf_char_cent();
		if (src[g_i + 1])
		{	
			// if (src[g_i + 1] != '%'){
			// ft_putchar(src[g_i + 1]);
			// }
			g_i++;
		}
		if (src[g_i] != '%')
			ft_putchar(src[g_i]);
		
	// }
	// else if(tempindex != -1)
	// 	ft_putchar(src[g_i]);
	// // else if (src[g_i] != '%' && src[g_i - 1] == '%')
	// // 	ft_putchar(src[g_i]);
	// // else if (src[g_i] != '%' && src[g_i - 1] == '%') 
	// else if (src[g_i] != '%') 
	// 	ft_putchar(src[g_i]);
	
}

int	find_start_for_with(const char *src, int g_var)
{
	if (src[g_i] == '*' && src[g_i++])
	{
		g_var = va_arg(g_my_list, int);
		if (g_var < 0)
		{
			g_m = 1;
			g_var *= -1;
		}
	}
	return (g_var);
}