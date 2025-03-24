/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:40:17 by plerick           #+#    #+#             */
/*   Updated: 2025/03/24 19:42:15 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void handling_error(void)
{
	perror("failed");
	exit(EXIT_FAILURE);
	return ;
}

int child1(int argc, char **argv, char **env, int fd[])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

int child2(int argc, char **argv, char **env, int fd[])
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	int fd[2];
	pid_t pid1;
	pid_t pid2;
	
	if (pipe(fd) == -1)
		handling_error;
	pid1 = fork();
	if (pid1 < 0)
		handling_error;
	if (pid1 == 0)
		child1(argc, argv, env, fd);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			handling_error;
		if (pid2 == 0)
			child2(argc, argv, env, fd);
	}
	if (pid1 != 0 && pid2 != 0)
	{
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}

	return (0);


	int		i = 0;
	int		j = 0;
	char	**path;
	
	while(env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i]+5, ':');
			while (path[j])
			{
				printf("%s\n", path[j]);
				j++;
			}
		}
		i++;
	}

	// (void)env;
	// int	i = 0;
	// char **cmd;
	// if (argc != 2)
	// 	return (0);
	// cmd = ft_split(argv[1], ' ');
	// while (i < 2)
	// {
	// 	printf("%s", cmd[i]);
	// 	i++;
	// }
	// https://github.com/gabcollet/pipex
}	