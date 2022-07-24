/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:23:10 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/24 22:34:41 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	format_percent(t_status status)
{
	char		*thestr;

	thestr = malloc(2);
	thestr[0] = '%';
	thestr[1] = 0;
	status = int_str_print(status, thestr);
	return (status);
}
