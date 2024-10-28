/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:00:56 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 01:20:14 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <stddef.h>  // Pour size_t
/*
	size_t	strlcat(char *dest, const char *src, size_t size) {
	size_t dest_len = 0;
	size_t src_len = 0;

//	Calculer la longueur de la chaîne de destination
	while (dest[dest_len] != '\0' && dest_len < size) 
	{
		dest_len++;
	}
//	Calculer la longueur de la chaîne source
	while (src[src_len] != '\0') 
	{
		src_len++;
	}
//	Si la taille spécifiée est inférieure ou égale à la longueur de la destination,
//	il n'y a pas de place pour concaténer, donc on retourne la longueur de la destination
	if (size <= dest_len) 
	{
		return dest_len + src_len;
	}
//	Concaténer la chaîne source à la chaîne de destination
	size_t to_copy = size - dest_len - 1; 
// 	Espace restant pour la chaîne source et le caractère nul
	if (to_copy > src_len) 
	{
		to_copy = src_len; // Ne pas copier plus que la longueur de la source
	}
//	Utiliser une boucle while pour copier les caractères de la chaîne source
	size_t i = 0;
	while (i < to_copy) 
	{
		dest[dest_len + i] = src[i];
		i++;
	}
//	Ajouter le caractère nul à la fin de la chaîne de destination
	dest[dest_len + to_copy] = '\0';

//	Retourner la longueur totale qui aurait été créée
	return (dest_len + src_len);
}
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;
	size_t	n;

	len_src = 0;
	len_dest = 0;
	i = 0;
	n = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest++;
	if (len_dest >= size)
		return (len_dest + len_src);
	n = len_dest;
	while (i < size - len_dest - 1 && src[i] != '\0')
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	const char	src1[] = "0123456789";
	const char	src2[] = "0123456789";
	char	dest1[20] = "abcdefgh";
	char	dest2[20] = "abcdefgh";
	size_t	size1 = 18;
	size_t	size2 = 18;

	size_t result1 = ft_strlcat(dest1, src1, size1 + 1);
	size_t result2 = strlcat(dest2, src2, size2 + 1);

	printf("Copied string: '%s'\n", dest1);
	printf("Length of source string: %zu\n", result1);
	printf("Copied string: '%s'\n", dest2);
	printf("Length of source string: %zu\n", result2);
	return (0);
}
*/
