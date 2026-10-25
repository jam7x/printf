/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaineau <bpaineau@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:59:10 by bpaineau          #+#    #+#             */
/*   Updated: 2026/10/25 15:59:18 by bpaineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_putnbr_base(unsigned long n, const char *base);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(void *ptr);

#endif
