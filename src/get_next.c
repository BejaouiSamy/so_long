/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:09:18 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 10:09:19 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

#define BUFFER_SIZE 42

// Pour allouer et copier une nouvelle ligne
char	*ft_append_buffer(char *line, char *buffer
		, int line_len, int buffer_len)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	if (line)
	{
		while (i < line_len)
		{
			new_line[i] = line[i];
			i++;
		}
		free(line);
	}
	j = 0;
	while (j < buffer_len)
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	new_line[i + j] = '\0';
	return (new_line);
}

void	bytes_read_extra_function(int bytes_read, char **stash)
{
	if (bytes_read < 0)
	{
		free(stash);
		stash = NULL;
		return ;
	}
}

// Fonction principale pour obtenir la ligne suivante
char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_char(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_append_buffer(stash, buffer,
				ft_strlen_until(stash, '\0'), bytes_read);
		stash = temp;
	}
	bytes_read_extra_function(bytes_read, &stash);
	if (bytes_read == 0 && (!stash || !*stash))
		return (NULL);
	return (extract_line(&stash));
}
