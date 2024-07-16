#include "include/ft_printf.h"

int main(void) {
	char *s = NULL;
	ft_printf("hello world\n");
	ft_printf("%s\n", s);
	ft_printf("%d\n", 42);
	ft_printf("%x\n", 42);
	return (0);
}
