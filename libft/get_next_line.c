/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:45:50 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/28 14:56:14 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static char	**stash_holder(void)
{
	static char	*stash = NULL;
	return (&stash);
}


char	*get_final_line(char **stash, char *line)
{
	char	*temp;
	char	*newline_pos;
	int		len;

	newline_pos = ft_strchr_gnl(line, '\n');
	if (newline_pos)
	{
		len = (newline_pos - line + 1);
		temp = malloc(len + 1);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy_gnl(temp, line, len + 1);
		*stash = ft_strdup_gnl(newline_pos + 1);
		free(line);
		return (temp);
	}
	else
	{
		free(newline_pos);
		*stash = ft_strdup_gnl("");
		return (line);
	}
}


char	*read_char(int fd, char *stash)
{
	ssize_t		char_read;
	char		*new_stash;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(stash, '\n'))
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			if ((char_read == 0 && stash[0] == '\0') || char_read == -1)
				return (free(stash), NULL);
			return (stash);
		}
		buffer[char_read] = '\0';
		new_stash = ft_strjoin_gnl(stash, buffer);
		free(stash);
		stash = new_stash;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		**stash_ptr = stash_holder();

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!*stash_ptr)
		*stash_ptr = ft_strdup_gnl("");
	*stash_ptr = read_char(fd, *stash_ptr);
	if (!*stash_ptr)
		return (NULL);
	line = get_final_line(stash_ptr, *stash_ptr);
	if (!line)
	{
		free(*stash_ptr);
		*stash_ptr = NULL;
		return (NULL);
	}
	return (line);
}


void	cleanup_get_next_line(void)
{
	char	**stash_ptr = stash_holder();

	if (*stash_ptr)
	{
		free(*stash_ptr);
		*stash_ptr = NULL;
	}
}
