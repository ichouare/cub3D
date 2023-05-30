
#include "get_next_line.h"

static int	num_of_words(char const *s, char c)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	j = 0;
	number = 0;
	while (*(s + i) != '\0')
	{
		j = 0;
		while (*(s + i) == c)
			i++;
		while (*(s + i) != c && *(s + i) != '\0')
		{
			i++;
			j++;
		}
		if (j != 0)
			number ++;
	}
	return (number);
}

static char	**mfree(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**set_number_of_letter(char **arr, char const *s, int c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (*(s + i) != '\0')
	{
		j = 0;
		while (*(s + i) == c)
			i++;
		while (*(s + i) != c && *(s + i) != '\0')
		{
			i++;
			j++;
		}
		if (j != 0)
		{
			arr[k] = ft_calloc(sizeof(char), (j + 1));
			if (!arr[k++])
				return (mfree(arr, k));
		}
	}
	return (arr);
}

static char	**ft_remplir(char **arr, char const *s, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*(s + i) != '\0')
	{
		j = 0;
		while (*(s + i) == c)
			i++;
		while (*(s + i) != c && *(s + i) != '\0')
		{
			arr[k][j] = *(s + i);
			i++;
			j++;
		}
		if (j != 0)
			k++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	k = num_of_words(s, c);
	arr = ft_calloc(sizeof(char *), (k + 1));
	if (!arr)
		return (NULL);
	arr[k] = NULL;
	if (!(set_number_of_letter(arr, s, c)))
		return (NULL);
	ft_remplir(arr, s, c);
	return (arr);
}