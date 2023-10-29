/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:38 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/10/13 12:24:02 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printchar(int c);

int		ft_printf(const char *format, ...);

int		ft_format(va_list arg, int i);

int		ft_printpercent(void);

int		ft_printstr(char *str);

int		ft_printnbr(int nbr);

int		ft_printhex(unsigned int nbr, const char f);

int		ft_printptr(unsigned long long ptr);

int		ft_printunsign(unsigned int nbr);

#endif