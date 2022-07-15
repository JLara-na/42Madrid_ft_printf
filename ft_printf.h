/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:44:02 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/15 21:44:11 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_status
{
	char	*string;
	char	format;
	int		position;
	int		len;
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	int		min;
	int		max;
	int		minz;
	int		maxz;
	int		stop;
	va_list	*args;

}	t_status;

int			ft_printf(char const *, ...);


//Format functions that will print the argumet values based on the status info.

t_status	format_c(t_status status);
t_status	format_s(t_status status);
t_status	format_p(t_status status);
t_status	format_int(t_status status);
t_status	format_u(t_status status);
t_status	format_x(t_status status);
t_status	format_percent(t_status status);

//This function will check over the flags and format flag, updating the status
//and calling the format functions.

t_status	param_detector(t_status status);

#endif
