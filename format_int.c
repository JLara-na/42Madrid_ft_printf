/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:31:00 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/22 19:58:22 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

t_status	print_only_num(t_status status, char *str)
{
	int	dif;

	dif = 0;
	while (str[dif])
	{
		if (str[dif] != '-' && str[dif] != '+' && str[dif] != ' ')
			write(1, &str[dif], 1);
		status.len++;
		dif++;
	}
	return (status);
}

t_status	int_str_print(t_status status, char *str)
{
	int		i;
	int		dif;

	i = 0;
	dif = status.min;
	if (str[0] == '-' || str[0] == ' ' || str[0] == '+')
		write(1, &str[0], 1);
	if (ft_strlen(str) < status.min && !status.minus)
	{
		while (dif-- != ft_strlen(str))
			status = space_or_zero(status);
	}
	status = print_only_num(status, str);
	if (ft_strlen(str) < status.min && status.minus)
	{
		while (dif-- != ft_strlen(str))
			status = space_or_zero(status);
	}
	free(str);
	return (status);
}

t_status	format_int(t_status status)
{
	long long int	nb;
	long long int	unsignednb;
	char			*str;

	nb = (long long int)va_arg(*status.args, int);
	unsignednb = nb;
	if (nb < 0)
		unsignednb *= -1;
	str = ft_itoa(unsignednb);
	while (ft_strlen(str) < status.max)
		str = zero_at_front(str);
	if (status.plus || status.space || nb < 0)
	{
		str = zero_at_front(str);
		if (nb < 0)
			str[0] = '-';
		else if (status.space)
			str[0] = ' ';
		else
			str[0] = '+';
	}
	status = int_str_print(status, str);
	return (status);
}
