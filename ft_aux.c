/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:56:48 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/15 21:44:23 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		write (1, " ", 1);
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
