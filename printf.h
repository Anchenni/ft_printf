/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:05 by anchenni          #+#    #+#             */
/*   Updated: 2021/01/04 01:07:26 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _PRINTF_H
# define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int g_w ;
int g_z;
int	g_l_value;
int g_prec;
int g_p;
int g_length_hex ;
int g_m ;
int g_compt;
int g_space;
int g_prec_neg;
va_list my_list;

void    ft_printf_char_cent(void);
void	ft_decimal_tohexa_plus(size_t n);
void	ft_putnbr_base_p(int nb, char *base);
void	ft_putnbr_base_compt(int nb, char *base);
void    ft_printf_percent(void);
void	find_length_hexa(size_t n);
unsigned int             ft_size_base(char *base);
void    ft_putnbr_base(int nb, char *base);
void    ft_printf_x(va_list *my_list);
void    ft_printf_bx(va_list *my_list);
void    ft_printf_i(va_list *my_list);
void    ft_printf_u(va_list *my_list);
void    ft_printf_char(va_list *my_list);
void	ft_printf_p(va_list *my_list);
int findIndex(char *tab, char element);
void    ft_printf(char *src, ... );
void ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
void    ft_printf_str(va_list *my_list);
void	ft_putnbr_long(signed long int nb);
int	find_leng_d(size_t d);
void    ft_printf_nbr(va_list *my_list);










// static void (*g_tabfunction[10]) (va_list *) = {printf_c, printf_s, printf_p,
// 	printf_d, printf_i, printf_u, printf_x, printf_xx};
// static void (*g_tabFunction[4]) (va_list *) ={ft_printf_str, ft_printf_char, ft_printf_nbr, ft_printf_p};    

#endif
