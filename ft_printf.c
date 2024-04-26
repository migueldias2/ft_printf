/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:13:52 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/24 20:18:38 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_format(char specifier, va_list args)
{
	int				count;
	unsigned long	ptr_val;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(args, int));
	else if (specifier == 'u')
		count += print_digit(va_arg(args, unsigned int));
	else if (specifier == 'p')
	{
		ptr_val = va_arg(args, unsigned long);
		if (ptr_val == 0)
			return (write(1, "(nil)", 5));
		count += print_str("0x");
		count += print_hexa(ptr_val, specifier);
	}
	else if (specifier == 'x' || specifier == 'X')
		count += print_hexa(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list				args;
	int					i;
	int					count;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*int	main()
{
	//testar s,d,u,i
	int num;
	num = ft_printf("ola eu sou o %s, hoje e dia %d, 
	%u, %i sao os dias a seguir\n", "miguel", 23, 24, 25 );
	ft_printf("%d\n", num);
	//testar p
	int i = 17;
	int *ptr = &i;
	ft_printf("%p e %c\n", ptr, 'n');
	printf("%p\n", ptr);
	// testar x e X
	ft_printf("%x, %X", -1, -1);
	printf("%x, %X", -1, -1);
	ft_printf("%x, %X\n", 40000000, 40000000);
        printf("%x, %X\n", 40000000, 40000000);
}*/
