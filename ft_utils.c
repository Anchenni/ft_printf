/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:22 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/09 23:43:53 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_cont++;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		++i;
		++str;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	long			result;
	int				neg;

	result = 0;
	neg = 0;
	i = g_i;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		g_i = i - 1;
		if (result < 0)
		{
			if (neg)
				return (0);
			else
				return (-1);
		}	
	}
	if (neg)
		return (-result);
	else
		return (result);
}
