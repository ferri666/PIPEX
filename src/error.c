/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:57:33 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/07 11:44:49 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	com_error(char *cmd, int status)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	exit(status);
}

void	fork_error(void)
{
	ft_putendl_fd("pipex: There was a forking error!", 2);
	exit(-1);
}

void	env_error(void)
{
	ft_putendl_fd("pipex: The Humans Killed The Enviroment, Gary!!", 2);
	exit(-1);
}
