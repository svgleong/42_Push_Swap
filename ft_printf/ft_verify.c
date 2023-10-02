/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:50:12 by svalente          #+#    #+#             */
/*   Updated: 2022/11/24 14:44:54 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verify(const char varf, va_list args)
{	
	if (varf == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (varf == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (varf == 'p')
		return (ft_putnbrpointer(HEX_LOW_BASE, va_arg(args, unsigned long), 0));
	else if (varf == 'd' || varf == 'i')
		return (ft_putnbrbase(DEC_BASE, va_arg(args, int)));
	else if (varf == 'u')
		return (ft_putnbrbase(DEC_BASE, va_arg(args, unsigned int)));
	else if (varf == 'x')
		return (ft_putnbrbase(HEX_LOW_BASE, va_arg(args, unsigned int)));
	else if (varf == 'X')
		return (ft_putnbrbase(HEX_UP_BASE, va_arg(args, unsigned int)));
	else if (varf == '%')
		return (ft_putchar('%'));
	return (0);
}
