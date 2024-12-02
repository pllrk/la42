/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:17:27 by plerick           #+#    #+#             */
/*   Updated: 2024/11/21 04:21:28 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_apres_next_line(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(sizeof(char), (my_strlen(buffer) - i + 1));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free (buffer);
	return (new_buffer);
}

char	*ft_avant_next_line(char *buffer)
{
	char	*to_return;
	int		i;

	i = 0;
	if (!buffer[i] || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	to_return = ft_calloc(sizeof(char), i + 2);
	if (to_return == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		to_return[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		to_return[i] = '\n';
	return (to_return);
}

char	*ft_free(int fd, char *buffer, char *tojoin, int *count)
{
	char	*temp;

	while (*count > 0)
	{
		tojoin[*count] = 0;
		temp = ft_strjoin(buffer, tojoin);
		free(buffer);
		buffer = temp;
		if (buffer == NULL)
			return (NULL);
		if (ft_strchr(tojoin, '\n'))
			break ;
		*count = read(fd, tojoin, BUFFER_SIZE);
	}
	return (buffer);
}

char	*ft_read(int fd, char *buffer)
{
	int		count;
	char	*temp;

	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	if (buffer == NULL)
		return (NULL);
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (temp == NULL)
	{
		free(buffer);
		return (NULL);
	}
	count = read(fd, temp, BUFFER_SIZE);
	buffer = ft_free(fd, buffer, temp, &count);
	free(temp);
	if (count < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	to_return = ft_avant_next_line(buffer);
	buffer = ft_apres_next_line(buffer);
	return (to_return);
}

/* int	main(void)
{
	int	fd;
	char	*laphrase;
	
	fd = open("sample1.txt", O_RDONLY);
	while ((laphrase = get_next_line(fd)) != NULL)
	{
		printf("%s", laphrase);
		free(laphrase);
	}
	close (fd);
	return (0);
}
 */