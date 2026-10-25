#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	return (count + ft_putnbr_base((unsigned long)nb, "0123456789"));
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789"));
}
