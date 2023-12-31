/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:14:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/29 12:01:07 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *str, char to_find)
{
	size_t	n;

	n = 0;
	while (n < ft_strlen(str)+1)
	{
		if (str[n] == to_find)
		{
			return ((char *)&str[n]);
		}
		n++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strchr("Ests",'e'));
	printf("%s\n", ft_strchr("",'c'));
	printf("%s\n", ft_strchr("Esto es esto que es esto estoes",'s'));
	printf("%s\n", ft_strchr("Esto es esto que es esto estoes",'\0'));
	printf("--------------------------\n");
	printf("%s\n", strchr("Ests",'e'));
	printf("%s\n", strchr("",'c'));
	printf("%s\n", strchr("Esto es esto que es esto estoes",'s'));
	printf("%s\n", strchr("Esto es esto que es esto estoes",'\0'));
	return (0);
}
*/