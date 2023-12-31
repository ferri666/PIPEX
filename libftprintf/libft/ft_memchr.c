/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:17:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/29 11:57:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return (s + i);
		else
			i++;
	}
	return (NULL);
}
