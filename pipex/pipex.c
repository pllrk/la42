/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:40:17 by plerick           #+#    #+#             */
/*   Updated: 2025/03/22 20:30:16 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(void)
{
	// int	n;
	// int	i = 1;

	// id = fork();
	// // ft_printf("id est : %d \n", id);
	// if(id == 0)
	// {
	// 	// ft_printf("coucou du child, mon ID est : %d\n", id);
	// 	n = 1;
	// }		
	// else
	// {
	// 	// ft_printf("coucou du parent, mon ID est : %d\n", id);
	// 	n = 5;
	// }
	// i = n;
	// while (i + 5 > n)
	// {
	// 	ft_printf("%d ", n);
	// 	n++;
	// }
	// if(id != 0)
	// 	wait(0);
	// return (0);

	// int	id_1;
	// int	id_2;
	// // int	parent_id;
	
	// // parent_id = getppid;
	// // if(argc != 5)
	// // 	return (0);
	// id_1 = fork();
	// id_2 = -1;
	// if (id_1 != 0)
	// 	id_2 = fork();
	// if (id_1 == 0)
	// 	ft_printf("id_1 = %d\n", getpid);
	// else if (id_2 == 0)
	// 	ft_printf("id_2 = %d\n", getpid);
	// else
	// {
	// 	ft_printf("parent ID = %d\n", getppid);
	// 	while(wait(NULL) != -1 || errno != ECHILD)
	// 		printf("waited\n");
	// }

	int fd[2];
	pip_t pid;
	
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		
	}


	return (0);
}	