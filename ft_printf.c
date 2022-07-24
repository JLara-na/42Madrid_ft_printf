/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:02:44 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/23 21:28:55 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_writestr(t_status status)
{
	while (status.str[status.pos] && status.str[status.pos] != '%')
	{
		write(1, &status.str[status.pos], 1);
		status.len++;
		status.pos++;
	}
	if (!status.str[status.pos])
		status.stop = 1;
	return (status);
}

int	ft_printf(char const *string, ...)
{
	va_list		varguments;
	t_status	status;

	status.pos = 0;
	status.len = 0;
	status.stop = 0;
	status.str = ft_strdup(string);
	va_start(varguments, string);
	status.args = &varguments;
	while (!status.stop)
	{
		status = status_reset(status);
		status = ft_writestr(status);
		if (!status.stop)
			status = param_detector(status);
	}
	free(status.str);
	va_end(varguments);
	return (status.len);
}
