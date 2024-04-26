/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:36:05 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/24 19:43:36 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}

int	print_digit(long n)
{
	char	*str;
	int		count;

	str = "0123456789";
	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n > 9)
		count += print_digit(n / 10);
	print_char(str[n % 10]);
	count++;
	return (count);
}

int	print_hexa(unsigned long n, char specifier)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (specifier == 'X')
		str = "0123456789ABCDEF";
	if (n >= 16)
		count += print_hexa((n / 16), specifier);
	count += print_char(str[n % 16]);
	return (count);
}
