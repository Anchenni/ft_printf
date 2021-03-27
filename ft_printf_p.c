#include "printf.h"
#include "stdio.h"


void	ft_decimal_tohexa(size_t n)
{
	g_length_hex = 0;
	if (n > 15)
	{
		ft_decimal_tohexa(n / 16);
		n %= 16;
	}
	if (n > 9)
		ft_putchar(n + 87);
	else
		ft_putchar(n + 48);
}
void	find_length_hexa(size_t n)
{
	if (n > 15)
	{
		find_length_hexa(n / 16);
		n %= 16;
	}
	if (n > 9)
		g_length_hex++;
	else
		g_length_hex++;
}


void	ft_printf_p(va_list *my_list)
{
	
	size_t num = va_arg(*my_list, size_t);

	int srccomplet = 0;

	find_length_hexa(num);
	g_length_hex += 2;
	// char buffer[20];
	// sprintf(buffer, "%d",  num); // ft_putnbr
	// ft_putstr(num); // ft_putstr
	if(g_w){
		if(g_w >= g_length_hex ){
			srccomplet = g_w - g_length_hex ;
					//  printf("\n g_w = %d \n", g_length_hex);

		}else
			srccomplet = g_w - 2;

	}
	if (g_z >= 1){

		while(srccomplet != 0){

			ft_putchar('0');  //* = ' ' 
			srccomplet--;

		}





		ft_putstr("0x");
		ft_decimal_tohexa(num);


	}else if (g_m >= 1){
		ft_putstr("0x");
		// printf("\n g_p = %d\n", g_p);
		if(num == 0 && g_prec > 0 ){

			srccomplet++;
			// if (g_p == 0 && num ){
			// 	ft_decimal_tohexa(num);
			// }
		}
		else if(g_p == 0){
			ft_decimal_tohexa(num);
			
		}
		if(g_w < g_length_hex ){	
			if(num == 0){
				ft_decimal_tohexa(num);
				srccomplet -= 1;
							}			
			find_length_hexa(num);
			if (!(num == 0)){
				if(g_w == 0){
					srccomplet = 0;
				}else
				srccomplet = g_w - g_length_hex - 2;
			}	
			if(!g_w){
				
				while(srccomplet != 0){

					ft_putchar(' ');  //* = ' ' 
					srccomplet--;
				}
				if(num != 0)
				ft_decimal_tohexa(num);
			}
		}else{
			
				find_length_hexa(num);
			if(g_w > g_length_hex){

				if(g_p && num == 0){
					srccomplet = g_w - 2;
				}else
					srccomplet = g_w - g_length_hex - 2;
			if(srccomplet < 0){
				srccomplet = 0;
			}
			while(srccomplet != 0){

			ft_putchar(' ');  //* = ' ' 
			srccomplet--;
		}
			}
		}
	}
	
	else{
		if(num == 0 && g_prec == 0 && g_w ){

			srccomplet = g_w - 2 ;
			if (num == 0 && g_p == 0){
				srccomplet--;
			}

		}
if(g_length_hex < g_w){
		if(num == 0 && g_w < g_length_hex){
			srccomplet++;
		}
			while(srccomplet  != 0){

			ft_putchar(' ');  //* = ' ' 
			srccomplet--;
		}
		}

		ft_putstr("0x");

		if(num != 0 && g_prec >= 0){

			ft_decimal_tohexa(num);
		}else if(num == 0 && g_p == 0){
			ft_decimal_tohexa(num);
		}
		// printf("\n g_w = %d \n", g_w);
	}
}
