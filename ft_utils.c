/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:22 by anchenni          #+#    #+#             */
/*   Updated: 2020/11/15 15:34:48 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
	g_cont += 1;
}
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1,&str[i], 1);
		i++;
	}
}
void	ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		nbr = -n;
		write(1, "-", 1);
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
	int i;

	i = 0;
	while (*str != '\0')
	{
		++i;
		++str;
	}
	return (i);
}