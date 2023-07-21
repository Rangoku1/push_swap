/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:36:07 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/21 18:21:27 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*before_n(char *str)
{
	int			i;
	char		*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*after_n(char *ptr)
{
	int		i;
	int		j;
	char	*n_line;

	i = 0;
	while (ptr[i] != '\n' && ptr[i])
		i++;
	if (ptr[i] == '\n')
		i++;
	n_line = malloc(ftstrlen(ptr) - i + 1);
	if (!n_line)
		return (NULL);
	j = 0;
	while (ptr[i])
		n_line[j++] = ptr[i++];
	n_line[j] = '\0';
	free(ptr);
	return (n_line);
}

int	read_fun(int read, char **line)
{
	if (read < 0)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line;
	char		*full;
	int			read_index;

	while (1)
	{
		read_index = read(fd, buffer, BUFFER_SIZE);
		if (read_fun(read_index, &line))
			return (NULL);
		buffer[read_index] = '\0';
		line = ftstrjoin(line, buffer);
		if (read_index == 0 && line[0] == '\0')
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		if (ftstrchr(buffer, '\n') || read_index < BUFFER_SIZE)
			break ;
	}
	full = before_n(line);
	line = after_n(line);
	return (full);
}
