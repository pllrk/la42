/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:34:01 by plerick           #+#    #+#             */
/*   Updated: 2025/03/26 19:24:57 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freestr(char **str)
{
	int	i;

	if (!str || !*str)
		return ((void)write(2, "fail to free\n", 13));
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

char	*find_the_path(char *cmd, char **env)
{
	char	**the_way;
	char	*the_com;
	char	*com;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = -1;
	while (*env && ft_strncmp(*env, "PATH=", 5))
		++env;
	if (!*env)
		return (ft_putstr_fd("PATH not found in envp\n", 2), NULL);
	the_way = ft_split(*env + 5, ':');
	the_com = ft_strjoin("/", cmd);
	while (the_way[++i])
	{
		com = ft_strjoin(the_way[i], the_com);
		if (access(com, X_OK) == 0)
			break ;
		free(com);
		com = NULL;
	}
	if (!com || !*com)
		return (free(the_com), ft_freestr(the_way), perror("Failed\n"), NULL);
	return (free(the_com), ft_freestr(the_way), com);
}

void	execute(char *argv, char **env)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		return (free(cmd), (void)write(2, "No command\n", 11));
	cmd_path = find_the_path(cmd[0], env);
	if (!cmd_path)
		return (ft_freestr(cmd), perror("No path\n"));
	if (execve(cmd_path, cmd, env) == -1)
	{
		ft_putstr_fd("failed execve\n", 2);
		ft_freestr(cmd);
	}
}
