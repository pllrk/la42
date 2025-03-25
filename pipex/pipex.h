/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:41:01 by plerick           #+#    #+#             */
/*   Updated: 2025/03/25 19:45:28 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h> // For 'wait' etc
# include <errno.h> // For perror
# include <fcntl.h> // For O_RDONLY...

int		child1(char **argv, char **env, int fd[]);
int		child2(char **argv, char **env, int fd[]);
void	handling_error(void);
void	execute(char *argv, char **env);
char	*the_path(char *cmd, char **env);
void	freestr(char **str);

#endif