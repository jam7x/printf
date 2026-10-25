/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaineau <bpaineau@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:00:02 by bpaineau          #+#    #+#             */
/*   Updated: 2026/10/25 16:00:22 by bpaineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	unsigned long	len;
	int				count;

	len = 0;
	while (base[len])
		len++;
	count = 0;
	if (n >= len)
		count += ft_putnbr_base(n / len, base);
	count += ft_print_char(base[n % len]);
	return (count);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	return (ft_putnbr_base(n, "0123456789ABCDEF"));
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	return (count + ft_putnbr_base((unsigned long)ptr, "0123456789abcdef"));
}
