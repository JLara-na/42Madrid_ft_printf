/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:44:02 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/19 20:33:58 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

//This structure will be modified by each function pasing down the instruction
//to perform diferent tasks.

typedef struct s_status
{
	char	*string; //Donde se almacena la string argumento
	va_list	*args;
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
	char	format;

}	t_status;

//This is the main function, it will start the process to write down the string.

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
t_status	ft_writestr(t_status status);

//This are some auxiliar functions that will be used inside some functions.

t_status	status_reset(t_status status);
t_status	space_or_zero(t_status status);
void		ft_space(int i);

//LIBFT functions

char		*ft_strdup(const char *s1);
int			ft_isdigit(int j);
int			ft_isalpha(int j);
size_t		ft_strlen(const char *j);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
#endif
