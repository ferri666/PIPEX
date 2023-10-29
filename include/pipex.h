/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:06:09 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/06 11:56:14 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

# define STDERR		2
# define FD_WRITE_END	1
# define FD_READ_END		0

void	check_arg(int argc);
void	get_path(char *cmd, char *envp[], char **f_path);
void	free_matrix(char **matrix);
void	acc_error(char **argcmd, char *path);
void	com_error(char *cmd, int status);
void	fork_error(void);
void	env_error(void);
char	*env_path(char *envp[]);

#endif