/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:41:01 by plerick           #+#    #+#             */
/*   Updated: 2025/03/26 16:04:54 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h> //for access
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h> // for 'wait' etc
# include <errno.h> // for perror
# include <fcntl.h> // for O_RDONLY...

void	child1(char **argv, char **env, int fd[]);
void	child2(char **argv, char **env, int fd[]);
void	handling_error(void);
void	execute(char *argv, char **env);
char	*find_the_path(char *cmd, char **env);
void	ft_freestr(char **str);

#endif