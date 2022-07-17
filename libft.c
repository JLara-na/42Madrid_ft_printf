/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:50:10 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/16 20:46:22 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *j)
{
	size_t	i;

	i = 0;
	while (j[i])
		i++;
	return (i);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = '\0';
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	mul;

	mul = (count * size);
	str = malloc(mul);
	if (str == (void *)0)
		return (NULL);
	ft_bzero(str, mul);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
