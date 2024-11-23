/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:17:51 by plerick           #+#    #+#             */
/*   Updated: 2024/11/21 01:17:53 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + count] = src[i];
		i++;
	}
	dest[i + count] = '\0';
	return (dest);
}

static char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	total_lengh;
	char	*new_str;

	total_lengh = my_strlen(str1) + my_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (total_lengh + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	new_str = ft_strcat(new_str, str1);
	new_str = ft_strcat(new_str, str2);
	return (new_str);
}
