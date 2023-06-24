/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:13:11 by ichouare          #+#    #+#             */
/*   Updated: 2023/06/23 19:12:32 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	found_nl(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != (char)c)
		i++;
	return (i);
}

//join function 
static char	*strimplement(char *str, char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*str;

	if (!s1 && !s2)
		return (NULL);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (found_nl(s1, '\0')
				+ found_nl(s2, '\0') + 1));
	if (!str)
		exit (0);
	return (strimplement(str, s1, s2));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	int		size;

	arr = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (found_nl(s, '\0') > len)
		size = len;
	else
		size = found_nl(s, '\0') - start;
	arr = (char *)(malloc(sizeof(char) * (size + 1)));
	if (!arr)
		exit (0);
	while (size--)
	{
		*(arr + i) = *(s + start + i);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

//fucntion strchr for '\n
char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}
