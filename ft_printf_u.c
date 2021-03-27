#include "printf.h"
#include "stdio.h"

void	ft_putnbr_u(unsigned int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		ft_putnbr_u(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
}
void    ft_printf_u(va_list *my_list)
{


	unsigned int num = va_arg(*my_list, int);
	int srccomplet = 0;
	int leng_d = 0;
	int leng_zero = 0;
	int leng_space;

	leng_d = find_leng_d(num);


	if (g_p > 0 ){
		
		if(g_prec >=0 ){
// 	 		printf("OK");
		if(num < 0){
			leng_d-- ;
		}
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

	 	ft_putchar('0');  //* = ' ' 
	 	srccomplet--;
		 
	 	}

		 

       
	
			ft_putnbr_u(num);
	 }else if (g_m >= 1 ){
		 
		 if(  g_prec > 0 && leng_d < g_prec){
			 
			 if(g_w > 0 && g_w < g_prec && leng_d < g_w && leng_d < g_prec && g_prec > 0 && g_w < g_prec && g_z > 0){
				 
				 leng_zero = g_w - leng_d;
			 }else{
			 	leng_zero = g_prec - leng_d;
			 }

			//  if(num == 0){
			// 	 leng_zero = g_w - g_prec;
			//  }
			 if(num < 0){
				 ft_putchar('-');
			 }
			if (g_prec_neg == 0 || g_z > 0){
			 while(leng_zero != 0){
		
	 			ft_putchar('0'); //* = ' ' 
	 			leng_zero--;
	 		}
			}
		 } else {
			 
			 if(num < 0){
				 ft_putchar('-');
			 }
		 }
		 

		
       if(!(num == 0) || (!g_p)){
		//    printf("g_m = %d neg = %d\n", g_m,g_prec_neg);
			ft_putnbr_u(num);
			if( g_prec_neg > 0 && g_z == 0){
			if(g_prec < g_w && g_m > 0 ){
				leng_space = g_prec - leng_d;
			}else
			 leng_space = g_w - leng_d;
			 
			 while (leng_space > 0)
			 {
				 ft_putchar(' ');
				 leng_space--;
			 }
			 
		 }
	   }
		 if(g_prec > 0 && g_w  && num == 0)
			ft_putnbr_u(num);
			else if(num == 0 && g_m == 1 && g_p == 1 && g_w == 0 ){
			ft_putnbr_u(num);

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
		
	 	while(leng_space != 0){
		
	 	ft_putchar(' ');  //* = ' ' 
	 	leng_space--;
	 	}
		
	 }
	 }
	 else{
		 
	
	 	while(srccomplet != 0){

	 		ft_putchar(' ');  //* = ' ' 
	 		srccomplet--;
	 	}
	  	
	
	//  	if (g_p == 0) 
	// g_print_p = 1;
		// printf("\n num %d \n", num);
		if(num < 0 && g_prec >= leng_d  ){

       
	
			ft_putnbr_u(num);
		}
		else if(num != 0 && g_prec >= 0){
			ft_putnbr_u(num);
		}else if(num == 0 && g_p == 0){
			ft_putnbr_u(num);
		}
		
	}


}
