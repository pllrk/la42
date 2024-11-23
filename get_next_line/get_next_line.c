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

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 10

// Fonction pour concaténer deux chaînes de caractères
char *ft_strjoin(char *s1, char *s2) {
    if (!s1 && !s2) return NULL;
    if (!s1) return strdup(s2);
    if (!s2) return strdup(s1);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 pour le caractère nul

    if (!result) return NULL;

    size_t i = 0;
    while (i < len1) {
        result[i] = s1[i];
        i++;
    }

    size_t j = 0;
    while (j < len2) {
        result[i + j] = s2[j];
        j++;
    }

    result[i + j] = '\0';
    free(s1); // Libérez s1 si nécessaire
    return result;
}

// Fonction pour lire une ligne à partir d'un descripteur de fichier
char *get_next_line(int fd) {
    static char *buffer = NULL; // Tampon statique pour stocker les données
    char temp[BUFFER_SIZE + 1]; // Tampon temporaire pour la lecture
    char *line = NULL; // Ligne à retourner
    int bytes_read;
    int i = 0;

    // Si le tampon est NULL, allouez-le
    if (!buffer) {
        buffer = malloc(1);
        buffer[0] = '\0';
    }

    // Lire jusqu'à ce qu'une nouvelle ligne soit trouvée ou que la fin du fichier soit atteinte
    while (1) {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            return NULL; // Erreur de lecture
        }
        if (bytes_read == 0) {
            // Si rien n'a été lu et que le tampon est vide, retournez NULL
            if (buffer[0] == '\0') {
                free(buffer);
                buffer = NULL;
                return NULL; // Fin de fichier
            }
            break; // Fin de fichier, mais il y a encore des données dans le tampon
        }

        temp[bytes_read] = '\0'; // Terminez la chaîne
        buffer = ft_strjoin(buffer, temp); // Concaténez le tampon avec les nouvelles données

        // Cherchez une nouvelle ligne dans le tampon
        while (buffer[i] && buffer[i] != '\n') {
            i++;
        }

        // Si une nouvelle ligne a été trouvée
        if (buffer[i] == '\n') {
            line = strndup(buffer, i + 1); // Copiez la ligne (y compris '\n')
            char *new_buffer = strdup(buffer + i + 1); // Créez un nouveau tampon sans la ligne lue
            free(buffer); // Libérez l'ancien tampon
            buffer = new_buffer; // Mettez à jour le tampon
            return line; // Retournez la ligne lue
        }
    }

    // Si nous sommes ici, cela signifie que nous avons atteint la fin du fichier
    if (buffer[0] != '\0') {
        line = strdup(buffer); // Copiez le reste du tampon
        free(buffer);
        buffer = NULL; // Réinitialisez le tampon
        return line; // Retournez le reste
    }

    free(buffer);
    buffer = NULL; // Réinitialisez le tampon
    return NULL; // Fin de fichier
}

/*
#define BUFFER_SIZE 10

static char	*ft_endoffile(char *all, char *temp)
{
	qe
}

static char	*ft_newline(char *temp, char *result, int i)
{
	w
}

static char	*stockbuff(char *buffer, char *result, int i)
{
	qwwr
}

char	*get_next_line(int fd)
{
	char	*result = NULL;
	char	buffer[BUFFER-SIZE];
	int	i;
	int	count;
	char	*all;

	while (1)
	{
		i = -1;
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			if (count == 0)
				return (all = ft_endoffile(result, buffer));
			if (count == -1)
				return (0);
		}
		while (++i < count)
		{
			if (buffer[i] == '\n')
			{
				all = ft_newline(buffer, result, i);
				break;
			}
			else
				result = ft_stockbuff(buffer, result, i);
		}
	}
	
	return(all);
*/
/*	if (i == BUFFER_SIZE)
	{
		temp = ((char *)malloc(sizeof(char) * BUFFER_SIZE + 1));
		if (temp == NULL)
			return(free(temp), NULL);
		read(fd, temp, BUFFER_SIZE);
		result = temp;
	}
*/
/*	temp = ((char *)malloc(sizeof(char) * BUFFER_SIZE + 1));
	if (temp == NULL)
	{
		free(temp);
		return(NULL);
	}
	read(fd, temp, BUFFER_SIZE);
	result = temp;
*/

int	main(void)
{
	int	fd;
	char	*laphrase;
	
	
	fd = open("sample.txt", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	laphrase = get_next_line(fd);
	printf("X%s", laphrase);
	laphrase = get_next_line(fd);
	printf("Y%s", laphrase);
	laphrase = get_next_line(fd);
	printf("Z%s", laphrase);
	free(laphrase);
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
