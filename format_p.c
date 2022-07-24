/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:04:45 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/24 21:29:39 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		ft_putnbr_hex(size_t nb)
{
	char		*base;
	static int 	count;
	
	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16);
		nb = nb % 16;
	}
	count++;
	ft_putchar(base[nb]);
	return (count);
}

int		ft_countnbr_hex(size_t nb)
{
	char		*base;
	static int 	count;
	
	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_countnbr_hex(nb / 16);
		nb = nb % 16;
	}
	count++;
	return (count);
}

t_status	format_p(t_status status)
{
	size_t  nb;
	int		i;
	int		count;
	int		dif;

	i = 0;
	nb = (size_t)va_arg(*status.args, void *);
	count = ft_countnbr_hex(nb) + 2;
	dif = status.min;
	if (count < status.min && !status.minus)
	{
		while (dif-- != count)
			status = space_or_zero(status);
	}
	write(1, "0x", 2);
	status.len += 2;
	status.len += ft_putnbr_hex(nb);
	if (count < status.min && status.minus)
	{
		while (dif-- != count)
			status = space_or_zero(status);
	}
	return (status);
}
