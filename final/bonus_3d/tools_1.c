/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:31:22 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 13:31:42 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_join2d(char **env, char *var)
{
	char	**p;
	int		i;

	if (var == NULL)
		return (env);
	if (env == NULL)
	{
		p = ft_calloc(sizeof(char *), 2);
		*p = var;
		return (p);
	}
	p = ft_calloc(sizeof(char *), ft_strlen2d(env) + 2);
	i = 0;
	while (env[i])
	{
		p[i] = env[i];
		i++;
	}
	p[i] = var;
	return (p);
}

size_t	ft_strlens(char *p, char a)
{
	size_t	i;

	i = 0;
	if (!p)
		return (0);
	while (*(p + i) != a && *(p + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*p;

	i = 0;
	s_len = ft_strlen(s);
	p = malloc(sizeof(char) * s_len + 1);
	if (!p)
		exit (0);
	while (*(s + i))
	{
		*(p + i) = *(s + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
