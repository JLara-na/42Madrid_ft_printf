/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:46 by jlara-na          #+#    #+#             */
/*   Updated: 2022/08/17 19:22:35 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	BLACK()
{
	printf("\033[1;30m");
}

void	RED()
{
	printf("\033[1;31m");
}

void	GREEN()
{
	printf("\033[1;32m");
}

void	YELLOW()
{
	printf("\033[1;33m");
}

void	BLUE()
{
	printf("\033[1;34m");
}

void	PURPLE()
{
	printf("\033[1;35m");
}


void	CIAN()
{
	printf("\033[1;36m");
}

void	WHITE()
{
	printf("\033[1;37m");
}

void	LINECLEAR()
{
	int	i = 0;
	while (i++ < 1)
		printf("\n");
}

int	main()
{
	char			c = 'A';
	char			*s = "Hola";
	int				d = INT_MAX;
	unsigned int	u = INT_MIN;
	int				x = 42;

	LINECLEAR();
	GREEN();
	printf("		|  COMPARADOR   |\n");
	RED();
	printf("\nLA SALIDA MÍNIMA (PRINTF NO IMPRIME NADA) ES 40.\n");
	printf("EL FLAG . TIENE PRIORIDAD SOBRE EL TAMAÑO MINIMO.\n");
	GREEN();	
	printf("\n		|       A       |\n");
	YELLOW();
	printf("		|    Format C   |\n");
	printf("		|    Flags -5   |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%-5c|\n", c));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%-5c|\n", c));
	GREEN();
	printf("\n		|      Hola     |\n");
	YELLOW();
	printf("		|    Format S   |\n");
	printf("		|   Flags -5.2  |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%-5.2s|\n", s));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%-5.2s|\n", s));
	GREEN();
	printf("\n		|      Hola     |\n");
	YELLOW();
	printf("		|    Fromat P   |\n");
	printf("		|   Flags  -12  |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%-12p|\n", s));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%-12p|\n", s));
	GREEN();
	printf("\n		|    INT_MAX    |\n");
	YELLOW();
	printf("		|   Format D&I  |\n");
	printf("		| Flags +-14.12 |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%+-14.12d|\n", d));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%+-14.12d|\n", d));
	GREEN();
	printf("\n		|    INT_MIN    |\n");
	YELLOW();
	printf("		|    Format U   |\n");
	printf("		|  Flags 014.12 |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%014.12u|\n", u));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%014.12u|\n", u));
	GREEN();
	printf("\n		|       42      |\n");
	YELLOW();
	printf("		|    Format x   |\n");
	printf("		|  Flags #-7.3  |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%#-7.3x|\n", x));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%#-7.3x|\n", x));
	YELLOW();
	printf("\n		|    Format X   |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%#-7.3X|\n", x));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%#-7.3X|\n", x));
	YELLOW();
	printf("\n		|    Format %%   |\n");
	CIAN();
	printf("\n");
	printf("ft_printf Salida ------------------> |%d|\n\n", ft_printf("ft_printf Escritura ---------------> |%%%%|\n"));
	printf("printf Salida ---------------------> |%d|\n", printf("printf Escritura ------------------> |%%%%|\n"));
	LINECLEAR();
	return (0);
}

