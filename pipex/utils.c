/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:34:01 by plerick           #+#    #+#             */
/*   Updated: 2025/03/25 19:45:13 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	freestr(char **str)
{

	
}

char	*the_path(char *cmd, char **env)
{
	
}

void execute(char *argv, char **env)
{
	char **cmd;
	char *cmd_path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		return (free(cmd), (void)write(2, "No command\n", 11));
	cmd_path = the_path(cmd[0], env);
	if (!cmd_path)
		return (freestr(cmd), free(cmd_path), perror("No path"));
	if (execve(cmd_path, cmd, env) == -1)
	{
		ft_putstr_fd("failed execve 1", 2);
		freestr(cmd);
		free(cmd_path);
	}
	
}