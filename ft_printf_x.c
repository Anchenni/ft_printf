/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:01:02 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/11 16:17:25 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_size_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[j])
		{
			if (base[j + 1] != '\0' && base[j + 1] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	nbr;

	nbr = nb;
	if (ft_size_base(base) == 0)
	{
		return ;
	}
	if (nbr >= ft_size_base(base))
		ft_putnbr_base((nbr / ft_size_base(base)), base);
	ft_putchar(base[nbr % ft_size_base(base)]);
}

unsigned int	claculat_space_and_zero_and_print_it(unsigned int num)
{
	if (g_prec > g_length_hex)
	{
		g_leng_space = g_w - g_prec;
		while (g_leng_space-- != 0)
			ft_putchar(' ');
		g_leng_zero = g_prec - g_length_hex;
		if (num == 0)
			g_leng_zero++;
		while (g_leng_zero-- != 0)
			ft_putchar('0');
	}
	else
	{
		g_leng_space = g_w - g_length_hex;
		if (g_prec == 0 && g_w > g_length_hex)
			g_leng_space++;
		if (g_prec == 0 && g_w > g_length_hex && g_w > g_prec && num != 0)
			g_leng_space--;
		while (g_leng_space-- > 0)
			ft_putchar(' ');
	}
	return (num);
}

unsigned int	calculat_leng_zero(unsigned int num)
{
	if (g_w > 0)
	{
		if (g_w < g_prec && g_prec > g_length_hex && g_w < g_length_hex)
			g_leng_zero = g_length_hex + 1;
		else if (num == 0 && g_prec)
			g_leng_zero = g_prec;
		else if (g_prec > g_length_hex && g_w > g_prec)
			g_leng_zero = g_prec - g_length_hex;
		else if (!(g_prec < g_length_hex && g_prec > 0))
		{
			if (g_w > g_length_hex)
			{
				if (g_prec > g_w && g_length_hex < g_prec)
					g_leng_zero = g_prec - g_length_hex;
				else
					g_leng_zero = g_w - g_length_hex;
			}
		}
	}
	return (num);
}

void	ft_printf_x(va_list *g_my_list)
{
	unsigned int	num;

	num = va_arg(*g_my_list, int);
	find_length_hexa(num);
	g_leng_space = 0;
	print_zero(num);
	if (g_z >= 1 && g_m == 0)
		find_leng_zero_spac_and_print_x(num);
	else if (g_m >= 1)
	{
		print_zero_and_space_x(num);
		calculat_space_and_print_it_x(num);
		if (g_w > g_prec)
			print_space_x(num);
	}
	else
		print_x(num);
}
