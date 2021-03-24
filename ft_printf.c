/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:42 by anchenni          #+#    #+#             */
/*   Updated: 2021/01/04 21:56:37 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int findIndex(char *tab, char element)
{
	int index = 0;
	
	for (index = 0; tab[index] != 0; index++)
	{

		if (tab[index] == element)
			return (index);
	}
	return (-1);
}
void		init_zero(void){
g_w = 0;
g_z = 0;
g_l_value = 0;
g_prec = 0;
g_p = 0;
g_length_hex  = 0;
g_m  = 0;
g_compt = 0;
g_space = 0;
g_prec_neg = 0;
}
int    ft_printf(char *src, ... )
{
	// changer tous les write par ft_putchar
	
	void (*tabFunction[9]) (va_list *) ={ft_printf_str, ft_printf_char, ft_printf_nbr,ft_printf_i,ft_printf_u,ft_printf_x,ft_printf_bx, ft_printf_p, 0};    
	// init_zero();
	char tabIndex[9] = {'s', 'c','d','i','u','x','X','p', 0};
	va_list my_list;
	int i = 0;
	int tempIndex=0;
	int j = 0;
	// int cont;

	va_start(my_list, src);
	// changer le for en while
	for( i = 0; src[i] != 0; i++)
	{	

	
		if(i != 0 && src[i - 1] == '%')
		{
			init_zero();
			
			while(src[i] == '0'){
				g_z = 1;
				i++;
			}
			
			while(src[i] == '-'){
				g_m += 1;
				i++;
			}
			if(src[i] == ' '){
				i++;
				g_space += 1;
			}
			
			if(src[i] == '*'){
				g_w = va_arg(my_list, int);

				if (g_w < 0){
					g_m = 1;
					g_w *= -1;
				}
				
				i++;
			}
			else {
					g_w = atoi(src + i);
												
				}
				
			while(src[i] <= '9' && src[i] >= '0'){
				i++;	
			}	
			
			while(src[i] == '-'){
				g_m += 1;
				i++;
			}
			if(src[i] == '.'){
				g_p += 1;
				i++; 
			}
			
			if(src[i] == '*'){
				// printf("OKK");
				
				g_prec = va_arg(my_list, int);
				if (g_prec < 0){
					g_m = 1;
					g_prec_neg = 1;
					g_prec *= -1;
				}

				i++;
			}
			else {
				
				g_prec = atoi(src + i);	
				if (g_prec < 0){
					g_m = 1;
					g_prec *= -1;
				}			
			}	
			while(src[i] == '-'){
				g_m +=1;
				i++;
			}
			while(src[i] <= '9' && src[i] >= '0'){
				i++;	
			}
			
			tempIndex = findIndex(tabIndex, src[i]);
			

			if (tempIndex != -1){
				(*tabFunction[tempIndex])(&my_list);
				 
			}
			
			
			

			else {

				if( src[i] == '%'){
					j++;
					if(j % 1 == 0 ){
						ft_printf_char_cent();
					}
					if(src[i + 1])
						i++;
					if(src[i] != '%')
						ft_putchar(src[i]);
					
				}else
				{
					ft_putchar(src[i]);
				}
				
			// printf("\nsrc de i = %s\n", &src[i] );
			}

		}else if(src[i]  != '%' ){
			write(1, &src[i], 1);
		}
		// printf("src de i = %s\n", &src[i] );

	}	
	return (g_cont);
}





// int		main()
// {
// 	int ncm_p = 5;
// 	ft_printf("%-p", &ncm_p);
// 	return 0;
// }







