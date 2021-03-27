#include "printf.h"
#include <stdio.h>


void    ft_printf_bx(va_list *my_list)
{
	unsigned int num = va_arg(*my_list, int);
	int srccomplet = 0;
	find_length_hexa(num);
	
	int leng_zero;
	int leng_space = 0;
									

			
	
	if (g_p > 0 && g_m == 0 && g_z == 0){
		
		if((g_prec) || (g_w) ){
		if( g_prec >= g_w && g_length_hex < g_prec){
			leng_zero = g_prec - g_length_hex;
			if(num == 0)
				leng_zero++;
			while(leng_zero != 0){
				ft_putchar('0');
				leng_zero--;
			}
		}else if(g_w >= g_prec  )
		{
			if(g_prec > g_length_hex ){
				leng_space = g_w - g_prec;
				while(leng_space != 0){
				ft_putchar(' ');
				leng_space--;
				}
				leng_zero = g_prec - g_length_hex;
				if(num == 0)
					leng_zero++;
				while(leng_zero != 0){
				ft_putchar('0');
				leng_zero--;
			}
			}
			else { 
			// printf("\n with = %d && g_leng_hex == %d\n", g_w, g_length_hex);	
			leng_space = g_w - g_length_hex;
			// printf("\nleng_space == %d\n", leng_space);
			if(g_prec == 0 && g_w > g_length_hex){
				leng_space++;
			}
			if(g_prec == 0 && g_w > g_length_hex && g_w > g_prec && num != 0){
				leng_space--;
			}
			while(leng_space > 0){
				ft_putchar(' ');
				leng_space--;
			}
			}
		}
		}
	}
	
	// char buffer[20];
	// sprintf(buffer, "%d",  num); // ft_putnbr
	// ft_putstr(num); // ft_putstr
	else if(g_w && g_m == 0 && g_z == 0){
		

		if(g_w >= g_length_hex )

			srccomplet = g_w - g_length_hex;
	}
	
	if (g_z >= 1 && g_m == 0){
		
	 	if ((num < 0) && (g_z == 1) && (leng_zero >= 0)){

			 if(g_length_hex > g_prec)
			ft_putchar('-');
		 }
		if(g_w > 0 ){
			if(g_w < g_prec && g_prec > g_length_hex && g_w < g_length_hex){
				
				leng_zero = g_length_hex + 1;
			}else
			if(num == 0 && g_prec){
				
				leng_zero = g_prec ;
			}else
			if(g_prec > g_length_hex && g_w > g_prec  ){
				// leng_zero = g_w - g_prec;
				
				leng_zero =  g_prec - g_length_hex;
			}else if (g_prec < g_length_hex && g_prec > 0){
				
				
			}else if( g_w > g_length_hex){
				if(g_prec > g_w && g_length_hex < g_prec){
					
					leng_zero = g_prec - g_length_hex;
				}else{
					
			leng_zero = g_w - g_length_hex;
				}
				
			}
		}	
		
		if(g_prec > 0 && g_w > 0 && g_prec < g_w && g_prec > g_length_hex){
			leng_space = g_w - g_prec;
		}else if(g_p && g_w  && g_w > g_prec) 
		{

			leng_space = g_w - g_length_hex;
		}
		while(leng_space != 0){
			ft_putchar(' ');
			leng_space--;
		}
		
		if(g_prec == 0 && g_w < g_length_hex && !g_p){
					leng_zero = 0;
				}
		else if(g_prec > 0 && g_prec < g_length_hex && g_w > 0){
			leng_zero = 0;
		}
	 	while(leng_zero != 0){

	 	ft_putchar('0');  //* = ' ' 
	 	leng_zero--;
		 
	 	}

		 

       if(!(num == 0) || (!g_p)){
	
		     	 ft_putnbr_base(num,"0123456789ABCDEF");
	   }
	 }else if (g_m >= 1){
		 
	 	if(  g_prec > 0 && g_length_hex < g_prec){
			 
			 leng_zero = g_prec - g_length_hex;
			//  if(num == 0){
			// 	 leng_zero = g_w - g_prec;
			//  }
			 if(num < 0){
				 ft_putchar('-');
			 }
			 if (g_prec_neg == 0 || g_z > 0){
			 while(leng_zero != 0){
		
	 		ft_putchar('0');  //* = ' ' 
	 		leng_zero--;
	 	}
			 }
		 } else {
			 	
			 if(num < 0){
				 ft_putchar('-');
			 }
		 }
		 
		 		//    printf("\n g_prec = %d\n",g_m );


       if(!(num == 0) || (!g_p)){
	
    	 ft_putnbr_base(num,"0123456789ABCDEF");
		 if( g_prec_neg > 0 && g_z == 0){
			if(g_prec < g_w && g_m > 0 ){
				leng_space = g_prec - g_length_hex;
			}else
			 leng_space = g_w - g_length_hex;
			 
			 while (leng_space > 0)
			 {
				 ft_putchar(' ');
				 leng_space--;
			 }
			 
		 }
	   }
		 else if(g_prec > 0 && g_w  && num == 0)
    	 ft_putnbr_base(num,"0123456789ABCDEF");
		 else if(num == 0 && g_m == 1 && g_p == 1 && g_w == 0 ){
			     	 ft_putnbr_base(num,"0123456789ABCDEF");

		 }

		 		if (g_w > g_prec ){
			if(g_w > g_length_hex && g_prec > 0 ){
					leng_space = g_w - g_prec;
					if(g_prec < g_length_hex){
						leng_space--;
					}
			}
			else if(g_w > g_length_hex && g_prec){
				
				leng_space = g_w - g_length_hex;
			}
			else if((g_w > 0 && !g_p) && g_length_hex < g_w){
				leng_space = g_w - g_length_hex;
			}else
			{
				leng_space = 0;
			}

		if(num < 0 && g_prec ){
			leng_space--;
			if( g_w > g_length_hex && g_prec < g_length_hex){
			  leng_space = g_length_hex - 1;

			}
			// 

		}
		
		if(g_m == 1 && g_length_hex < g_w && g_p && g_prec == 0 && num != 0){
			
			leng_space = g_w - g_length_hex;
		}
		if(num == 0 && g_prec == 0 && g_m > 0){
			
			leng_space = g_w;
			if (g_p == 0){
				// printf("%d\n", leng_space);
				leng_space--;
			}
		}
		
	 	while(leng_space != 0){
		
	 	ft_putchar(' ');  //* = ' ' 
	 	leng_space--;
	 	}
		
	 }
	 }
	 else{
		//  printf("srccomm = %d\n", srccomplet);
	 	while(srccomplet != 0){

	 		ft_putchar(' ');  //* = ' ' 
	 		srccomplet--;
	 	}
	  	
	
	//  	if (g_p == 0) 
	// g_print_p = 1;
		// printf("\n num %d \n", num);
		if(num < 0 && g_prec >= g_length_hex  ){

       
	
		     	 ft_putnbr_base(num,"0123456789ABCDEF");

		}
		else if(num != 0 && g_prec >= 0){
			    	 ft_putnbr_base(num,"0123456789ABCDEF");

		}else if(num == 0 && g_p == 0){
			    	 ft_putnbr_base(num,"0123456789ABCDEF");

		}
		
	}


}