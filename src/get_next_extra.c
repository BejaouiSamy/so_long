#include "../Includes/so_long.h"

int	ft_strlen_until(char *str, char c)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_sstrdup(char *s)
{
	int	len;
	char	*dup;
	
	len = ft_strlen_until(s, '\0');
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

int	has_char(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	extract_line_1(char **stash, char **line, int *line_len)
{
	if (!*stash || !**stash)
		return;
	*line_len = ft_strlen_until(*stash, '\n');
	if ((*stash)[*line_len] == '\n')
		(*line_len)++;
	*line = malloc(*line_len + 1);
	if (!*line)
		return;
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int	line_len;

	line = NULL;
	line_len = 0;
	extract_line_1 (stash, &line, &line_len);
	ft_memcpy(line, *stash, line_len);
	line[line_len] = '\0';
	if ((*stash)[line_len] == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	else
	{
		new_stash = ft_sstrdup(*stash + line_len);
		free(*stash);
		*stash = new_stash;
	}
	return (line);
}
