#include <stdio.h>
#include "printf.h"
int main(int ac, char const **argv)
{
	
	printf("%-*.*s", -7, -3, "yolo");
	printf("\n\n");
	ft_printf("%-*.*s", -7, -3, "yolo");
	
	// printf("!%57c!\n!%-76.*s!\n!%--38p!\n!%-*.159X!\n!%000193.93X!" ,55,-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De",(void*)15808961691193129302lu,168,1914174653u,2368364743u);
	// printf("\n\n");
	// ft_printf("!%57c!\n!%-76.*s!\n!%--38p!\n!%-*.159X!\n!%000193.93X!" ,55,-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De",(void*)15808961691193129302lu,168,1914174653u,2368364743u);
}	
