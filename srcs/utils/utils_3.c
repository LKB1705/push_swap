/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:53:27 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/11 19:54:42 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

static int	count_words(const char *s, char delim)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != delim && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == delim)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*alloc_words(const char *str, char delim)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && str[len] != delim)
		len++;
	word = malloc((len + 1) * sizeof (char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len + 1);
	return (word);
}

static void	free_all(char **result, int i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		j;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[j] = alloc_words(s, c);
			if (!result[j])
				return (free_all(result, j - 1), NULL);
			j++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[j] = NULL;
	return (result);
}

t_node	*value_to_rank(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		r;

	i = a;
	while (i)
	{
		r = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				r++;
			j = j->next;
		}
		i->value = r;
		i = i->next;
	}
	return (a);
}

