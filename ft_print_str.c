/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaineau <bpaineau@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:00:55 by bpaineau          #+#    #+#             */
/*   Updated: 2026/10/25 16:01:12 by bpaineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
