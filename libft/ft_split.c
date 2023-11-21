/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:32:16 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/13 19:09:53 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while ((char)s[i])
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
	words[j] = NULL;
	return (words);
}
