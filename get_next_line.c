/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:25:43 by malmeida          #+#    #+#             */
/*   Updated: 2021/03/11 12:36:25 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	char		*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

static void	freebird(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static int	returnado(int rd, char **line, char **saved, char **temp)
{
	int			i;

	i = 0;
	if (rd > 0 || ft_strchr(*saved, '\n'))
	{
		while ((*saved)[i] != '\n')
			i++;
		*line = ft_substr(*saved, 0, i);
	}
	else if (rd == 0)
	{
		*line = ft_strdup(*saved);
		freebird((void *)saved);
		return (0);
	}
	else
	{
		freebird((void *)saved);
		return (-1);
	}
	*temp = ft_substr(*saved, i + 1, 10000000);
	freebird((void *)saved);
	*saved = *temp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	static char	*saved[10000];
	int			rd;

	if (fd < 0 || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!saved[fd])
		saved[fd] = ft_calloc(1, 1);
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		temp = ft_strjoin(saved[fd], buff);
		freebird((void *)&saved[fd]);
		saved[fd] = temp;
		if (ft_strchr(saved[fd], '\n') != 0)
			break ;
	}
	return (returnado(rd, line, &saved[fd], &temp));
}
