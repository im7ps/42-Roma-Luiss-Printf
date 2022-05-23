/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:13:42 by sgerace           #+#    #+#             */
/*   Updated: 2022/05/23 19:26:23 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const	char *string, ...)
{
	va_list	list;
	int		i;

	va_start(list, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 'c')
			{
				i += ft_putchar(va_arg(list, int));
			}
			else if (string[i] == 's')
			{
				i += ft_putstr(va_arg(list, char *));
			}
			else if (string[i] == 'p')
			{
				i += ft_print_ptr(va_arg(list, unsigned long), "0123456789abcdef");
			}
			else if (string[i] == 'd' || string[i] == 'i')
			{
				i += ft_print_int(va_arg(list, int));
			}
			else if (string[i] == 'u')
			{
				i += ft_print_u_int(va_arg(list, unsigned int));
			}
			else if (string[i] == 'x')
			{
				i += ft_print_num_hex(va_arg(list, unsigned int), "0123456789abcdef");
			}
			else if (string[i] == 'X')
			{
				i += ft_print_num_hex(va_arg(list, unsigned int), "0123456789ABCDEF");
			}
			else if (string[i] == '%')
			{
				i += ft_putchar('%');
			}
		}
		i++;
	}
	return (i);
}

int main(void)
{
	char anything = '%';
	char *anything2 = "asdasdasd";
	int anything3 = 12453;
	unsigned char anything4 = 0123456789abcdef;
	unsigned char anything5 = 0123456789ABCDEF;
	void *anything6 = &anything2;

	printf("Questa è con printf: %c\n", anything);
	ft_printf("%c\n", anything);

	printf("Questa è con printf: %s\n", anything2);
	ft_printf("%s\n", anything2);

	printf("Questa è con printf: %d\n", anything3);
	ft_printf("%d\n", anything3);

	printf("Questa è con printf: %x\n", anything4);
	ft_printf("%x\n", anything4);

	printf("Questa è con printf: %X\n", anything5);
	ft_printf("%X\n", anything5);

	printf("Questa è con printf: %p\n", anything6);
	ft_printf("%p\n", anything6);

	return (0);
}