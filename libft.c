/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:50:10 by jlara-na          #+#    #+#             */
/*   Updated: 2022/07/19 20:43:42 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 size_t	ft_strlen(const char *j)
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

 void	*ft_calloc(size_t count, size_t size)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (i <= (n - 1) && n != 0 && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
