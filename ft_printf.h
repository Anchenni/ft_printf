/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:05 by anchenni          #+#    #+#             */
/*   Updated: 2021/04/09 23:50:07 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
int				g_w;
int				g_z;
int				g_l_value;
int				g_prec;
int				g_p;
int				g_length_hex;
int				g_m;
int				g_compt;
int				g_space;
int				g_prec_neg;
int				g_cont;
int				g_i;
int				g_j;
int				g_leng_d;
int				g_leng_space;
int				g_leng_zero;
int				g_srccomplet;
int				g_leng_prec;
int				g_leng_str;
char			*g_nul;
int				g_continu;
signed long int	g_h;
va_list			g_my_list;
int				g_tempindex;
void			init_zero(void);
void			ft_printf_char_cent(void);
void			ft_decimal_tohexa_plus(size_t n);
void			ft_putnbr_base_p(int nb, char *base);
void			ft_putnbr_base_compt(int nb, char *base);
void			find_length_hexa(size_t n);
unsigned int	ft_size_base(char *base);
void			ft_putnbr_base(int nb, char *base);
void			ft_printf_x(va_list *g_my_list);
void			ft_printf_bx(va_list *g_my_list);
void			ft_printf_i(va_list *g_my_list);
void			ft_printf_u(va_list *g_my_list);
void			ft_printf_char(va_list *g_my_list);
void			ft_printf_p(va_list *g_my_list);
int				findindex(char *tab, char element);
int				ft_printf(const char *src, ...);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
size_t			ft_strlen(const char *str);
void			ft_printf_str(va_list *g_my_list);
void			ft_putnbr_long(signed long int nb);
int				find_leng_d(size_t d);
void			ft_printf_nbr(va_list *g_my_list);
int				ft_atoi(const char *str);
int				print_mines_and_space(int num);
int				find_leng_space_when_with_bigger_than_prec(int	num);
int				print_space_when_num_diff_than_zero(int	num);
int				print_space_and_num(int	num);
int				find_leng_space_and_check_mines(int	num);
int				find_leng_space_and_zero(int num);
int				print_space(int	num);
int				print_mines_and_zero(int num);
int				print_space(int	num);
int				print_mines_and_zero(int num);
int				find_leng_space_and_zero(int num);
int				find_leng_zero(int num);
void			print_space_char(char src);
void			when_there_is_a_mines(char *src, int i);
void			calculate_leng_space(char *src, int i);
void			calculat_leng_str(char *src);
void			print_str(char *src, int i);
void			print_zero_and_str(char	*src);
void			find_leng_space_str(void);
void			print_space_str(char *src);
void			wene_with_exist(char *src, int i);
void			when_prec_is_bigger_than_with(char	*src, int	i);
void			find_leng_str_and_print_space(char	*src, int i);
void			calculate_spac_and_print_str(char *src, int i);
unsigned int	find_leng_zero_spac_and_print_x(unsigned int num);
unsigned int	print_zero(unsigned int num);
unsigned int	print_zero_and_space_x(unsigned int num);
unsigned int	print_x(unsigned int num);
unsigned int	calculat_space_and_print_it_x(unsigned int num);
unsigned int	calc_leng_spac2_x(unsigned int num);
unsigned int	print_space_x(unsigned int num);
unsigned int	calculat_leng_zero(unsigned int num);
unsigned int	claculat_space_and_zero_and_print_it(unsigned int num);
unsigned int	print_bx(unsigned int num);
unsigned int	calculat_space_and_print_it_bx(unsigned int num);
unsigned int	find_leng_zero_spac_and_print_bx(unsigned int num);
size_t			calculat_space_p(size_t num);
size_t			when_there_is_a_mines_p(size_t num);
size_t			whene_there_is_no_mines_p(size_t num);
void			ft_decimal_tohexa(size_t n);
unsigned int	calculat_leng_zero_u(unsigned int num);
unsigned int	calculate_leng_zero2_u(unsigned int num);
unsigned int	print_spac_mines_and_zero_u(unsigned int num);
unsigned int	calculat_leng_space2_u(unsigned int num);
unsigned int	print_space_u(unsigned int num);
void			find_percent(const char *src);
int				print_mines_and_zero(int num);
int				print_space(int num);
int				print_space_nbr(int num);
int				test_if_number(const char *str, int i, int neg);
int				find_start_for_with(const char *src, int g_var);
void			flags_star_prec(const char *src);
void			find_flag_with_prec(const char *src);
void			find_star_prec(const char *src);
void			find_star_with(const char *src);
void			find_flags_and_percent(const char *src);
size_t			print_space_p(size_t num);
unsigned int	calculate_space_u(unsigned int num);

static char		g_tabindex[8] = {'s', 'c', 'd', 'i', 'u', 'x', 'X', 'p'};

static	void	(*g_tabfunction[8])(va_list	*) = {ft_printf_str,
	ft_printf_char, ft_printf_nbr, ft_printf_i,
	ft_printf_u, ft_printf_x,
	ft_printf_bx, ft_printf_p};

#endif
