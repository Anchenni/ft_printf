#include "printf.h"

int main(int ac, char const **argv)
{
	char *s_hidden = "hi low";
	printf("!%5.0s!", "Hello");
	printf("\n\n");
	ft_printf("!%5.0s!", "Hello");


	// printf("!%-7.-3s!", "yolo");
	// printf("\n\n");
	// ft_printf("!%-7.-3s!", "yolo");

}	
