/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:33:50 by anchenni          #+#    #+#             */
/*   Updated: 2021/01/04 00:25:09 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

void	ft_putnbr_long(signed long int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);
	}
	else
		{
		ft_putchar(nb + '0');
		}
}
int	find_leng_d(size_t d)
{
	ssize_t number;

	number = d;
	 if(number <= -2147483647){
			 g_l_value++;
		 }
	g_l_value = 0;
	if (number <= 0)
	{
		number *= -1;
		g_l_value = 1;
	}
	while (number > 0)
	{
		number /= 10;
		g_l_value++;
		
	}
				

	return (g_l_value);

}

void    ft_printf_nbr(va_list *my_list)
{
	int num = va_arg(*my_list, int);
	int srccomplet = 0;
	int leng_d = 0;
	int leng_zero = 0;
	int leng_space = 0;

			leng_d = find_leng_d(num);

	if (g_p > 0 ){
		// printf("\n1\n");
		
		if(g_prec >=0 ){
		// printf("\n2\n");

// 	 		printf("OK");
		if(num < 0){
			leng_d-- ;
		}
		// printf(" g_prec = %d , leng_d = %d, g_p = %d, g_w = %d \n", g_prec, leng_d, g_p, g_w);
		if( g_prec >= g_w && leng_d <= g_prec && g_m == 0){
			
			if( num < 0 && leng_d > g_prec){

			}else
			leng_zero = g_prec - leng_d;
			if(num < 0){
				ft_putchar('-');
				leng_zero++;
			}
			if(num == 0){
				leng_zero++;
			}
			if(num < 0){
			leng_zero-- ;
			}
			// if(g_w < g_prec && leng_d < g_prec && leng_d < g_w && !g_z && leng_space != 0){
			// 	leng_space = g_prec - g_w;
			// 	while(leng_space != 0){
			// 	ft_putchar(' ');
			// 	leng_space--;
			// }
			// }
			while(leng_zero != 0){
				ft_putchar('0');
				leng_zero--;
			}
		}else if(g_w >= g_prec && g_m == 0)
		{
			

			if(g_prec > leng_d ){
				if(!g_w){
					leng_space = g_prec - leng_d;
				}
				leng_space = g_w - g_prec;
				if (num < 0){
					leng_space--;
				}
				while(leng_space != 0){
				ft_putchar(' ');
				leng_space--;
				}
				leng_zero = g_prec - leng_d ;
				if(num < 0){
					ft_putchar('-');
				}
				if(num == 0 && g_z == 0){
				leng_zero++;
				}
				while(leng_zero != 0){
				ft_putchar('0');
				leng_zero--;
			}
			}
			else {
				
			leng_d = find_leng_d(num);
			leng_space = g_w - leng_d;
			if( num == 0){
				leng_space = g_w - g_prec;
			}
			while(leng_space > 0 ){
				ft_putchar(' ');
				leng_space--;
			}
			}
		}

		}
	}
	// printf("\n g_prec = %d\n",g_prec );
	// char buffer[20];
	// sprintf(buffer, "%d",  num); // ft_putnbr
	// ft_putstr(num); // ft_putstr
	 else if(g_w){

		if(g_w >= find_leng_d(num) )

			srccomplet = g_w - find_leng_d(num);
	}

	if (g_z >= 1 && g_m == 0){
	 	if ((num < 0) && (g_z == 1) && (leng_zero >= 0)){
			 if(leng_d > g_prec)
			ft_putchar('-');
		 }
			
	 	while(srccomplet != 0){

	 	write(1, "0", 1);  //* = ' ' 
	 	srccomplet--;
		 
	 	}

		 
		signed long int h = num;

       
		if(( num == 0 && g_prec == 0 && g_p == 0 && g_w == 0))
			ft_putnbr_long(h);
		else if(g_w > 0 || num != 0)
			ft_putnbr_long(h);
		//  else if(g_prec > 0 )
		//  	ft_putnbr_long(h);
		// else if(g_w > 0 && num == 0){
		//  	ft_putnbr_long(h);
		// }	 
	 }else if (g_m >= 1){
		 
		 if(  g_prec > 0 && leng_d < g_prec){
			 if(g_w == 0 && g_prec > leng_d){
				 leng_zero = 0;
			 }else
			 leng_zero = g_prec - leng_d;
			//  if(num == 0){
			// 	 leng_zero = g_w - g_prec;
			//  }
			 if(num < 0){
				 ft_putchar('-');
			 }
			 if(g_z > 0 && g_w > leng_d && num != 0 && g_w < g_prec)
			 	{
					 leng_zero = g_w - leng_d;
				 }
			 
			 while(leng_zero != 0){
		
	 		write(1, "0", 1);  //* = ' ' 
	 		leng_zero--;
	 	}
		 } else {
			 
			 if(num < 0){
				 ft_putchar('-');
			 }
		 }
		 
		 		//    printf("\n g_prec = %d\n",g_m );

signed long int h = num;

       if(!(num == 0) || (!g_p))
	
		 ft_putnbr_long(h);
		 if(g_prec > 0 && g_w  && num == 0)
		 			 ft_putnbr_long(h);
					  else if(num == 0 && g_m == 1 && g_p == 1 && g_w == 0 ){
		 			 ft_putnbr_long(h);

		 }

		 		if (g_w > g_prec ){
			if(g_w > leng_d && g_prec > 0 ){
					leng_space = g_w - g_prec;
					if(g_prec < leng_d){
						leng_space--;
					}
			}
			else if(g_w > leng_d && g_prec){
				
				leng_space = g_w - leng_d;
			}
			else if((g_w > 0 && !g_p) && leng_d < g_w){
				leng_space = g_w - leng_d;
			}else
			{
				leng_space = 0;
			}

		if(num < 0 && g_prec ){
			leng_space--;
			if( g_w > leng_d && g_prec < leng_d){
			  leng_space = leng_d - 1;

			}
			// 

		}
		
		if(g_m == 1 && leng_d < g_w && g_p && g_prec == 0 ){
			
			leng_space = g_w - g_prec;
		}
		if(leng_d > g_prec && num < 0 && g_w > leng_d && g_p > 0){
			leng_space = g_w - leng_d - 1;
		}
		if(g_m > 0 && g_w > leng_d && leng_d > g_prec && g_p > 0 && num > 0)
			leng_space = g_w - leng_d;
		
	 	while(leng_space != 0){
		
	 	write(1, " ", 1);  //* = ' ' 
	 	leng_space--;
	 	}
		
	 }
	 }
	 else{
		 
	
	 	while(srccomplet != 0){

	 		write(1, " ", 1);  //* = ' ' 
	 		srccomplet--;
	 	}
	  	
	
	//  if (g_p == 0) 
	// g_print_p = 1;
		// printf("\n num %d \n", num);
		if(num < 0 && g_prec >= leng_d){
		signed long int h = num;
		 ft_putnbr_long(h);
		}
		else if(num != 0 && g_prec >= 0){
			ft_putnbr(num);
		}else if(num == 0 && g_p == 0){
			ft_putnbr(num);
		}
		
	}


}
