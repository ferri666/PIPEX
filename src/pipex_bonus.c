/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:56:54 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/07 11:31:32 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

static int	openfile(char *filename, int mode)
{
	if (mode == FD_READ_END)
	{
		if (access(filename, F_OK))
		{
			ft_putstr_fd("pipex: no such file or directory: ", 2);
			ft_putendl_fd(filename, 2);
			return (STDIN_FILENO);
		}
		if (access(filename, R_OK))
		{
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putendl_fd(filename, 2);
			exit (-1);
		}
		return (open(filename, O_RDONLY));
	}
	if (!access(filename, F_OK) || access(filename, W_OK))
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	else
		return (STDOUT_FILENO);
}

static void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;
	int		status;

	args = ft_split(cmd, ' ');
	if (find_chr(args[0], '/') > -1)
		path = args[0];
	else
		get_path(args[0], env, &path);
	status = execve(path, args, env);
	if (status == -1)
	{
		free_matrix(args);
		com_error(cmd, status);
	}
	free_matrix(args);
	free(path);
	exit(status);
}

static void	redir(char *cmd, char **envp, int fdin)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		if (waitpid(pid, &status, WNOHANG) == -1)
			perror("waiting error");
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			exec(cmd, envp);
	}
}

//fd[0] = IN
//fd[1] = OUT
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		i;

	i = 3;
	check_arg(argc);
	if (!env_path(envp))
		env_error();
	fd[0] = openfile(argv[1], FD_READ_END);
	fd[1] = openfile(argv[argc - 1], FD_WRITE_END);
	if (fd[1] < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(argv[argc - 1], 2);
		return (123);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	redir(argv[2], envp, fd[0]);
	while (i < argc - 2)
		redir(argv[i++], envp, 1);
	exec(argv[i], envp);
	return (1);
}
