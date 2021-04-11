/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:54:02 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/11 15:37:49 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	calculate_space_u(unsigned int num)
{
	if (g_m == 1 && g_leng_d < g_w && g_p && g_prec == 0)
	{
		if (num != 0)
			g_w -= g_leng_d;
		g_leng_space = g_w - g_prec;
	}
	return (num);
}
