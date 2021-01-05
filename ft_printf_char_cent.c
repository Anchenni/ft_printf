#include "printf.h"

void    ft_printf_char_cent(void)
{
    int srccomplet = 0;
	char src;
	src = '%';
	
	
	if(g_w > 0  && g_z == 0){
		g_w--;
		if(g_m > 0 )
				   ft_putchar(src);
		while(g_w != 0){
		ft_putchar(' ');
		g_w--;
		}
		if(g_m <= 0)
	   ft_putchar(src);

	
	}	
	else if (g_p > 0)
		ft_putchar(src);
	
	else{
	if(g_w){
		if(g_w >= 1 )
			srccomplet = g_w - 1;
	}

	if (g_z >= 1){
	 	while(srccomplet != 0){

	 	write(1, "0", 1);  //* = ' ' 
	 	srccomplet--;
	 	}
		 ft_putchar(src);
	 }else
		if (g_m >= 1){
		ft_putchar(src); // ft_putstr
		while(srccomplet != 0){

		write(1, " ", 1);  //* = ' ' 
		srccomplet--;
		}
	}
	else{
	
		while(srccomplet != 0){

			write(1, " ", 1);  //* = ' ' 
			srccomplet--;
		}
		ft_putchar(src); // ft_putstr
	}
}
}