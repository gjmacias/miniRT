/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:54:56 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/02 11:54:59 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	w;
	int	i;
	int	n;

	w = 0;
	i = 0;
	n = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] != c)
			n = 1;
		else if ((unsigned char)s[i] == c && n == 1)
		{
			w++;
			n = 0;
		}
		i++;
	}
	if (n == 1)
		w++;
	return (w);
}

static int	ft_word_len(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static void	*ft_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
	return (NULL);
}

static int	ft_find_words(const char *s, int i, int wlen, char *word)
{
	int	k;

	k = 0;
	while (k < wlen)
		word[k++] = s[i++];
	word[k] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**words;
	int				wlen;
	int				j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = (char **)ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	while (words && (char)s[i])
	{
		if ((char)s[i] == c)
			i++;
		else
		{
			wlen = ft_word_len(s, c, i);
			words[j] = (char *)malloc(sizeof(char) * (wlen + 1));
			if (!words[j])
				return (ft_free(words));
			i = ft_find_words(s, i, wlen, words[j++]);
		}
	}
	return (words);
}
