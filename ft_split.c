/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:44:33 by mabdessm          #+#    #+#             */
/*   Updated: 2024/04/30 18:03:51 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			i++;
		}
	}
	return (nb);
}

static int	len_word(char const *s, char c, int index)
{
	int	i;
	int	nb;
	int	lenword;

	i = 0;
	nb = 0;
	lenword = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			if (nb == index)
				lenword++;
			i++;
		}
	}
	return (lenword);
}

static char	*get_word(char const *s, char c, int index)
{
	char	*word;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	word = malloc(sizeof(char) * len_word(s, c, index) + 1);
	if (!word)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			if (nb == index)
			{
				word[j] = s[i];
				j++;
			}
			i++;
		}
	}
	word[len_word(s, c, index)] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	i = 0;
	split = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!split)
		return (NULL);
	while (i < count_words(s, c))
	{
		split[i] = get_word(s, c, i + 1);
		i++;
	}
	split[i] = NULL;
	return (split);
}
