/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:56:48 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/19 21:19:29 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	status_reset(t_status status)
{
	status.format = 'w';
	status.hash = 0;
	status.zero = 0;
	status.minus = 0;
	status.space = 0;
	status.plus = 0;
	status.dot = 0;
	status.min = 0;
	status.max = 0;
	status.minz = 0;
	status.maxz = 0;
	return (status);
}

void ft_space(int i)
{
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
	}
}

t_status	space_or_zero(t_status status)
{
	if (status.format == 'c' || status.format == 's' || status.format == 'p')
	{
		write (1, " ", 1);
	}
	else 
	{
		if (status.zero && !status.dot && !status.minus)
			write(1, "0", 1);
		else
			write (1, " ", 1);

	}
	status.len++;
	return (status);
}
