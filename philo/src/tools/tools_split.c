/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:35:28 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/18 17:35:38 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		word_count(char const *s, char c);
static char		*get_word(char const *s, char c);
static char		**fill_split(char **str, char const *s, char c);
static void		free_split(char **str, unsigned int words);

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	word_total;

	if (s == NULL)
		return (NULL);
	word_total = word_count(s, c);
	str = malloc(sizeof(char *) * (word_total + 1));
	if (str == NULL)
		return (NULL);
	if (!fill_split(str, s, c))
		return (NULL);
	return (str);
}

static char	**fill_split(char **str, char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			str[i] = get_word(s, c);
			if (!str[i])
			{
				free_split(str, i);
				return (NULL);
			}
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	str[i] = NULL;
	return (str);
}

static int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	char			*word;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **str, unsigned int words)
{
	while (words > 0)
	{
		words--;
		free(str[words]);
	}
	free(str);
}