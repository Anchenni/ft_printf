#include <stdio.h>
#include "printf.h"
int main(int ac, char const **argv)
{
	
	
	static char *s_hello = "hello world";
	
	printf("!%-107.*u!" ,-168,2003619509u);
	printf("\n\n");	
	ft_printf("!%-107.*u!" ,-168,2003619509u);
	printf("\n\n");	
	printf("!%-3.7u!", 3267);
	printf("\n\n");	
	ft_printf("!%-3.7u!", 3267);
	
// ft_printf("%---34c%-107.*u" ,7,-168,2003619509u)
	// printf("!%-78.100u!" ,2490445787u);
	// printf("\n\n");
	// ft_printf("!%-78.100u!" ,2490445787u);

}	
