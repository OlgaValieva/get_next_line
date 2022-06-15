/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:07:06 by carys             #+#    #+#             */
/*   Updated: 2021/12/21 13:45:15 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd, char *str)
{
	char	*buff;
	int		w_read;

	w_read = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && w_read != 0)
	{
		w_read = read (fd, buff, BUFFER_SIZE);
		if (w_read == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[w_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim(char *str)
{
	char	*line;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (str[i])
		line[k++] = str[i++];
	line[k] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_reader(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_trim(str);
	return (line);
}
