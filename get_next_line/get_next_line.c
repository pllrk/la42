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

char	*get_next_line(int fd)
{
	char	*str;


}

int	main(void)
{
	int	fd = 

	return (0);
}




/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
    
    char* fileName = "sample.txt";

    int fd = open(fileName, O_RDWR);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened successfully!\n", fileName);
    }

    char *buffer = "Hello Educative User!\n";

    int bytesWritten = write(fd, buffer, strlen(buffer));

    printf("%d bytes written successfully!\n", bytesWritten);

    return 0;
}
*/
