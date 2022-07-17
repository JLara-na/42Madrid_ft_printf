/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:32:42 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/17 18:51:33 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	format_c(t_status status)
{
	char	arg;
	int		dif;

	arg = va_arg(*status.args, int);
	dif = 0;
	while (dif + 1 < status.min && !status.minus)
	{
		write(1, " ", 1);
		status.len++;
		dif++;
	}
	write(1, &arg, 1);
	status.len++;
	while (dif + 1 < status.min && status.minus)
	{
		write(1, " ", 1);
		status.len++;
		dif++;
	}
	return (status);
}