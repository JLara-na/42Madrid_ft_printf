/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:02:44 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/17 19:41:20 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status ft_writestr(t_status status)
{
	while (status.string[status.position] 
			&& status.string[status.position] != '%')
	{
		write(1, &status.string[status.position], 1);
		status.len++;
		status.position++;
	}
	if (!status.string[status.position])
		status.stop = 1;
	return (status);
}

int			ft_printf(char const *string, ...)
{
	va_list		varguments;
	t_status	status;
	
	status.position = 0;
	status.len = 0;
	status.stop = 0;
	status.string = ft_strdup(string);
	va_start(varguments, string);
	status.args = &varguments;
	while (!status.stop)
	{
		status = status_reset(status);
		status = ft_writestr(status);
		if (!status.stop)
			status = param_detector(status);
	}
	free(status.string);
	va_end(varguments);
	return (status.len);
}
