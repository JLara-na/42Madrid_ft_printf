/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:33:38 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/19 21:23:13 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_process(t_status status, char	*mainstr)
{
	char	*processedstr;
	int		i;

	i = 0;
	if (!mainstr)
	{
		processedstr = ft_strdup("(null)");
		return (processedstr);
	}
	if (status.dot && !status.max && !status.maxz)
		processedstr = ft_strdup("");
	else if (((unsigned long)status.max < ft_strlen(mainstr) && status.max)
		|| status.maxz)
	{
		processedstr = ft_calloc(status.max + 1, sizeof(char));
		while (i < status.max)
		{
			processedstr[i] = mainstr[i];
			i++;
		}
	}
	else
		return (ft_strdup(mainstr));
	return (processedstr);
}

t_status	format_s(t_status status)
{
	char	*arg;
	int		i;
	size_t	dif;

	arg = str_process(status, va_arg(*status.args, char *));
	i = 0;
	dif = status.min;
	if (ft_strlen(arg) < (unsigned long)status.min && !status.minus)
	{
		while (dif-- != ft_strlen(arg))
			status = space_or_zero(status);
	}
	while (arg[i])
	{
		write(1, &arg[i], 1);
		status.len++;
		i++;
	}
	if (ft_strlen(arg) < (unsigned long)status.min && status.minus)
	{
		while (dif-- != ft_strlen(arg))
			status = space_or_zero(status);
	}
	free(arg);
	return (status);
}
