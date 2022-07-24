/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:32:42 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/23 21:52:53 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	format_c(t_status status)
{
	char	arg;
	int		i;

	arg = va_arg(*status.args, int);
	i = 0;
	while (i + 1 < status.min && !status.minus)
	{
		write(1, " ", 1);
		status.len++;
		i++;
	}
	write(1, &arg, 1);
	status.len++;
	while (i + 1 < status.min && status.minus)
	{
		write(1, " ", 1);
		status.len++;
		i++;
	}
	return (status);
}
