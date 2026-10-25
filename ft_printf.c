#include "ft_printf.h"

static int	ft_dispatch(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), c));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int				 count;
	int				 ret;
	int				 i;

	va_start(ap, fmt);
	count = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
			ret = ft_dispatch(fmt[++i], &ap);
		else
			ret = ft_print_char(fmt[i]);
		if (ret < 0)
			return (va_end(ap), -1);
		count += ret;
		i++;
	}
	va_end(ap);
	return (count);
}
