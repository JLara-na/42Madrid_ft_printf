/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:58:40 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/13 22:45:10 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	format_detector(t_status status)
{
	if (status.format == 'c')
			status = format_c(status);
	if (status.format == 's')
			status = format_s(status);
	if (status.format == 'p')
			status = format_p(status);
	if (status.format == 'd' || status.format == 'i')
			status = format_int(status);
	if (status.format == 'u')
			status = format_u(status);
	if (status.format == 'x' || status.format == 'X')
			status = format_x(status);
	if (status.format == '%')
			status = format_percent(status);
	return (status);
}

static t_status	flags_detector(t_status status)
{
	if (ft_isalpha(status.string[status.position])
		|| status.string[status.position] == '%')
			status.format = status.string[status.position];
	else if (status.string[status.position] == '-')
			status.minus = 1;
	else if (status.string[status.position] == '0')
			status.zero = 1;
	else if (status.string[status.position] == '.')
			status.dot = 1;
	else if (status.string[status.position] == '#')
			status.hash = 1;
	else if (status.string[status.position] == ' ')
			status.space = 1;
	else if (status.string[status.position] == '+')
			status.plus = 1;
	else if (ft_isdigit(status.string[status.position]) && !status.dot)
			status.min = status.min * 10
			+ (status.string[status.position] - 48);
	else if (ft_isdigit(status.string[status.position]) && status.dot)
			status.max = status.max * 10
			+ (status.string[status.position] - 48);
	else
			status.stop = 1;
	status.position++;
	return (status);
}

t_status	param_detector(t_status status)
{
	status.position++;
	while (status.format == "\0" && !status.stop)
			status = flags_detector(status);
	if (!status.stop)
			status = format_detector(status);
	return (status);
}
