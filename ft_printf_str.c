/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:34 by anchenni          #+#    #+#             */
/*   Updated: 2021/01/04 22:12:47 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"



void    ft_printf_str(va_list *my_list)
{

	int srccomplet = 0;
	int leng_prec;
	int i = 0;
	char *src = va_arg(*my_list, char *);
	char *nul = src ;
	if(src == NULL){
		src = "(null)";
	}
	//  printf("\n prec = %s\n", nul);
	// printf("\n with = %d\n", g_w);

	// printf("\n w = %d", g_w);
	// 	printf("\n prec = %d", g_prec);
	
	int leng_str = ft_strlen(src);
	if(g_w > 0 && g_m == 0){
		 
		if(g_w >= g_prec){    
			
			if (g_w > 0 && g_prec == 0 && nul != NULL){
				
				
			if (g_w > leng_str && g_p == 0 )	{
				
			}
			leng_prec = g_w;

			}
			else	
				if (g_prec > leng_str || g_w > leng_str)	{
					
					
					leng_prec = g_w - leng_str;
				}
				else {

					leng_prec = g_w - g_prec;	

				}
				if( g_prec < leng_str  ){

					if (g_w > leng_str && g_prec ==  0 && !g_p){
						

						leng_prec = g_w - leng_str;
					}				
					else{
					leng_prec = g_w - g_prec;	

					}
				}
				if(g_w > leng_str ){
					if(nul == NULL && g_w > 0 && g_prec > 0 && g_w > g_prec && g_w > leng_str){
						leng_prec = g_w - g_prec;
					}else	
					if( nul == NULL  && g_w < leng_str){
						
						leng_prec = g_w ;
					}else if(nul == NULL && g_w > leng_str && !g_p ){
						
						leng_prec = g_w - ft_strlen(src);
					}else if(nul == NULL)
					{
						leng_prec = g_w;
					}
					
				
			while(leng_prec != 0){
				ft_putchar(' ');
				leng_prec--;
			}
			}else if(g_p && leng_str >= g_w)
			{
				while(leng_prec != 0){
				ft_putchar(' ');
				leng_prec--;
			}
			}
			if(g_prec > leng_str){
				
			 	leng_prec = leng_str;
			}
			else if (g_w > leng_str && g_p == 0 ){
				
						leng_prec = g_w - leng_str;
					}	
			else
				{
				leng_prec = g_prec;
			}
			if (g_w  ){							


				if (g_w > 0 && g_prec == 0 ) {
					if(g_w && g_p ){
					}
						if(g_p > 0  && g_prec == 0 && g_w > 0){
							
						}else
						 
						 if ((nul != NULL || !g_p )){
							
							ft_putstr(src);
						}else if(g_w > 0 && g_w > leng_str && g_p == 0){
							ft_putstr(src);
						}
				}else{

				while(leng_prec > 0 && src[i]){
					ft_putchar(src[i++]);//* = ' ' 
					leng_prec--;
					
				}
				}
				
			}
			

		}	else if (g_w < leng_str){
			if(leng_str > g_prec ){
				leng_str = g_prec;
			}
			while(leng_str > 0 && src[i]){
					ft_putchar(src[i++]);//* = ' ' 
					leng_str--;
					
				}
		}else if(leng_str == 1 || leng_str == 0){
			srccomplet = g_w;
			while( srccomplet != 0){
				ft_putchar(' ');

				srccomplet--;
			}
		}
		else{
			if (g_w > leng_str ){
				srccomplet = g_w - leng_str;
				while( srccomplet != 0){
				ft_putchar(' ');

				srccomplet--;
			}
			
			while(leng_str > 0 && src[i]){
					ft_putchar(src[i++]);//* = ' ' 
					leng_str--;
					
				}
			}
		}
	}


		else { 

			if(g_w ){
				
				int m = ft_strlen(src);
				if(g_w >= m ){
					srccomplet = g_w - ft_strlen(src);
				}else
				{
					srccomplet = leng_str;
				}
				
			}
			if (g_z >= 1){

				while(srccomplet != 0){

					ft_putchar('0');  //* = ' ' 
					srccomplet--;
				}
				ft_putstr(src);
			}else
				if (g_m >= 1){
					
					if(g_p && g_prec < leng_str && g_prec > g_w){
						i = 0;
						if(leng_str < g_prec){
						while(g_prec != 0){
							ft_putchar(src[i++]);//* = ' ' 
							g_prec--;
						}
						}else
						{
								ft_putstr(src);
						}
						if (g_w > 0)
						srccomplet = leng_str - g_prec; 

						while(srccomplet != 0){

						ft_putchar(' ');  //* = ' ' 
						srccomplet--;
					}

					}
					else {
						if (g_w && g_prec < leng_str && g_p){
							if(g_prec_neg > 0 && g_prec < leng_str ){
								srccomplet = leng_str;
								
							}else
								srccomplet = g_prec;
						if(g_prec_neg == 1){
							srccomplet++;
							
						}
						// printf("leng src = %d\n", srccomplet);
						while(srccomplet > 0){
							ft_putchar(src[i++]);//* = ' ' 
							srccomplet--;
						}
						if (g_w > g_prec )
							srccomplet = g_w - g_prec;
						if(g_prec_neg == 1){
							srccomplet--;
						}
						if(g_prec_neg > 0 && g_prec < leng_str ){
								srccomplet = g_w - leng_str;
								
						}	
						while(srccomplet > 0){
							ft_putchar(' ');
						// write(1, " ", 1);  //* = ' ' 
						srccomplet--;
					}
					}else if(g_w > 0 ){
						 ft_putstr(src);
					}else if(g_w == 0 && g_prec > 0){
						ft_putstr(src);
					}else if(g_w == 0 && g_prec == 0 && !g_p){
						ft_putstr(src);
					}
						
						} // ft_putstr
						if (g_w > leng_str){
							
							
							
					while(srccomplet != 0){

						ft_putchar(' ');  //* = ' ' 
						srccomplet--;
					}

						}
					// else if(g_prec == 0 && g_prec < leng_str){
					// 		printf("G prec  = %d \n", g_prec);
					// 		srccomplet = g_prec;
						
						
					// 	while(srccomplet != 0){

					// 	write(1, " ", 1);  //* = ' ' 
					// 	srccomplet--;
					// }
					// 	}
				}
				else{
						
					if (g_prec > leng_str )	
						leng_prec = leng_str;
					else 
						leng_prec = g_prec;

					// while(leng_prec != 0){

					// 	write(1, " ", 1);  //* = ' ' 
					// 	leng_prec--;
					// }
					
					// printf("g = %d", g_prec);

					while(leng_prec != 0 ){
					ft_putchar(src[i++]);//* = ' ' 
					leng_prec--;
					
				} // ft_putstr
						
						
				}
				
				if(!g_p && !g_w && g_m == 0)
					 ft_putstr(src);
				g_p = 0;
		}
		
	}

