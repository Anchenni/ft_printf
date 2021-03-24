#include <stdio.h>
#include "printf.h"
int main(int ac, char const **argv)
{
	
	
	static char *s_hello = "hello world";
	// printf("!%57c!\n%-76.*s!\n%--38p!\n%-*.159X!\n%000193.93X!\n" ,55,-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De",(void*)15808961691193129302lu,168,1914174653u,2368364743u);
	// printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
	// ft_printf("!%57c!\n%-76.*s!\n%--38p!\n%-*.159X!\n%000193.93X!" ,55,-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De",(void*)15808961691193129302lu,168,1914174653u,2368364743u);
	// printf("!%-76.*s!",-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De");
	// printf("\n\n");
	// ft_printf("!%-76.*s!",-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De");
	printf("!%-5.0x!", 0);
	printf("\n\n");
	ft_printf("!%-5.0x!", 0);
	printf("\n\n");
	printf("!%-3x!", 0);
	printf("\n\n");
	ft_printf("!%-3x!", 0);
	printf("\n\n");
	printf("!%-175.96%%-153.x!" ,822360617u);
	printf("\n\n");
	ft_printf("!%-175.96%%-153.x!" ,822360617u);
}	
