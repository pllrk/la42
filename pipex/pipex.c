/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:40:17 by plerick           #+#    #+#             */
/*   Updated: 2025/03/26 19:23:27 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handling_error(void)
{
	perror("failed\n");
	exit(EXIT_FAILURE);
	return ;
}

void	child1(char **argv, char **env, int fd[])
{
	int	filein;

	close(fd[0]);
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (handling_error());
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (handling_error());
	if (dup2(filein, STDIN_FILENO) == -1)
		return (handling_error());
	close(fd[1]);
	close(filein);
	execute(argv[2], env);
	exit(1);
}

void	child2(char **argv, char **env, int fd[])
{
	int	fileout;

	close(fd[1]);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (handling_error());
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (handling_error());
	if (dup2(fileout, STDOUT_FILENO) == -1)
		return (handling_error());
	close(fd[0]);
	close(fileout);
	execute(argv[3], env);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5 || (!argv[1] || !argv[2] || !argv[3] || !argv[4] || !env))
		return (ft_putstr_fd("Not enough argument\n", 2), 0);
	if (pipe(fd) == -1)
		return (handling_error(), 2);
	pid1 = fork();
	if (pid1 < 0)
		return (handling_error(), 2);
	if (pid1 == 0)
		child1(argv, env, fd);
	pid2 = fork();
	if (pid2 < 0)
		return (handling_error(), 2);
	if (pid2 == 0)
		child2(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
