/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:07:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/29 11:57:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_printnbr(int nbr)
{
	int		ret;
	char	*num;

	ret = 0;
	num = ft_itoa(nbr);
	ret = ft_printstr(num);
	free(num);
	return (ret);
}

static int	ft_num_len(unsigned int n)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = 10;
	while (n != 0)
	{
		i++;
		n = n / remainder;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		len;

	len = ft_num_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	while (n != 0)
	{
		res[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (res);
}

int	ft_printunsign(unsigned int nbr)
{
	int		ret;
	char	*num;

	ret = 0;
	if (nbr == 0)
		ret += write(1, "0", 1);
	else
	{
		num = ft_uitoa(nbr);
		ret += ft_printstr(num);
		free(num);
	}
	return (ret);
}

/*
int	main(void)
{
	int s1;
	int s2;
	
	s1 = ft_printf("hola\n");
	s2 = printf("hola\n");
	ft_printf("%d   vs    %d", s1, s2);
}
*/