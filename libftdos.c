/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftdos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:27:10 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/22 00:38:30 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int j)
{
	return ((j >= 'A' && j <= 'Z') || (j >= 'a' && j <= 'z'));
}

int	ft_isdigit(int j)
{
	return (j >= '0' && j <= '9');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		c = '0' + (nb % 10);
	}
	else
		c = '0' + nb;
	write(1, &c, 1);
}

static unsigned int	ft_dcount(long nb)
{
	size_t	dcount;

	dcount = 0;
	if (nb < 0)
	{
		dcount++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		dcount++;
	}
	return (dcount);
}

char	*ft_itoa(long long int n)
{
	long long int	nb;
	unsigned int	dcount;
	char			*out;

	nb = n;
	dcount = ft_dcount(nb);
	out = ft_calloc(dcount + 2, sizeof(char));
	if (!out)
		return (NULL);
	if (nb < 0)
	{
		out[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		out[0] = '0';
	while (nb > 0)
	{
		out[dcount] = ('0' + (nb % 10));
		nb /= 10;
		dcount--;
	}
	return (out);
}
