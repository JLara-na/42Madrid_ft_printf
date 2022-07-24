/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:25:53 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/24 02:26:40 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hexbase(unsigned int nb, char *base)
{
	static int 	count;

	count = 0;
	if (nb >= (unsigned int)ft_strlen(base))
	{
		ft_putnbr_hexbase(nb / (unsigned int)ft_strlen(base), base);
		nb = nb % (unsigned int)ft_strlen(base);
	}
	count++;
	ft_putchar(base[nb]);
	return (count);
}

t_status	xmin_or_xmay(unsigned int nb, t_status status)
{
	if (status.hash && nb != 0)
	{
		if (status.format == 'x')
			write(1, "0x", 2);
		if (status.format == 'X')
			write(1, "0X", 2);
		status.len += 2;
	}
	if (status.format == 'x')
		status.len += ft_putnbr_hexbase(nb, "0123456789abcdef");
	if (status.format == 'X')
		status.len += ft_putnbr_hexbase(nb, "0123456789ABCDEF");
	return (status);
}

t_status	format_x(t_status status)
{
	unsigned int nb;
	int		count;
	int		dif;

	nb = va_arg(*status.args, int);
	count = ft_countnbr_hex(nb);
	dif = status.min;
	if (count < status.min && !status.minus)
	{
		while (dif-- != count)
			status = space_or_zero(status);
	}
	status = xmin_or_xmay(nb, status);
	if (count < status.min && status.minus)
	{
		while (dif-- != count)
			status = space_or_zero(status);
	}
	return (status);
}
