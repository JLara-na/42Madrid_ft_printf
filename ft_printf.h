/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:44:02 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/28 18:53:26 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>

//This structure will be modified by each function pasing down the instruction
//to perform diferent tasks.

typedef struct s_status
{
	char	*str;
	va_list	*args;
	int		pos;
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

int			ft_printf(const char *string, ...);

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

//INT functions

t_status	print_only_num(t_status status, char *str);
t_status	int_str_print(t_status status, char *str);

//This are some auxiliar functions that will be used inside some functions.

t_status	ft_writestr(t_status status);
t_status	status_reset(t_status status);
t_status	space_or_zero(t_status status);
char		*zero_at_front(char *str);
t_status	ft_zero(t_status status);

//LIBFT functions

char		*ft_strdup(const char *s1);
int			ft_isdigit(int j);
int			ft_isalpha(int j);
int			ft_strlen(const char *j);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putchar(char c);
void		ft_putnbr(int n);
char		*ft_itoa(long long int n);
int			ft_countnbr_hex(size_t nb);

t_status	min_max_detector(t_status status);
#endif
