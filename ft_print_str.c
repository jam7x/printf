#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
