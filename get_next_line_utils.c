/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:40:12 by malmeida          #+#    #+#             */
/*   Updated: 2021/03/11 14:08:40 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	int				i;
	int				len;

	len = 0;
	while (s1[len])
		len++;
	ptr = (char *)malloc(sizeof(*ptr) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i;
	int				z;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	z = ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * (z + i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	z = 0;
	while (s2[z])
	{
		str[i] = s2[z];
		i++;
		z++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*s;
	size_t			n;

	n = nmemb * size;
	ptr = malloc(n);
	if (ptr == NULL)
		return (ptr);
	s = (unsigned char *)ptr;
	while (n--)
		*s++ = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	rlen;

	if (!s)
		return (0);
	rlen = ft_strlen((char *)s);
	if (start >= rlen)
	{
		str = malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	if (rlen < len)
		return (ft_strdup(s + start));
	str = (char *)malloc(len + 1);
	if (!(str))
		return (0);
	s1 = start;
	s2 = 0;
	while (s1 < rlen && s2 < len)
		str[s2++] = s[s1++];
	str[s2] = '\0';
	return (str);
}
