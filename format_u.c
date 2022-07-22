/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:19:00 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/22 20:48:45 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	format_u(t_status status)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(*status.args, unsigned int);
	str = ft_itoa(nb);
	while (ft_strlen(str) < status.max)
		str = zero_at_front(str);
	status = int_str_print(status, str);
	return (status);
}
