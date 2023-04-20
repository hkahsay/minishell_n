/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:34:32 by vgejno            #+#    #+#             */
/*   Updated: 2023/04/20 14:23:49 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrwords(const char *s, char c)
{
	size_t	i;
	size_t	nbr;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			nbr++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (nbr);
}

static char	*ft_writewords(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	word = my_malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_words(size_t i, char **ptr)
{
	while (i > 0)
	{
		my_free(ptr[i - 1]);
		i--;
	}
	my_free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_words;
	size_t	i;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_nbrwords(s, c);
	ptr_words = my_malloc (sizeof(char *) * (words + 1));
	if (!ptr_words)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = ft_writewords(s, c);
		if (!ptr_words[i])
			ft_free_words(i, ptr_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}
