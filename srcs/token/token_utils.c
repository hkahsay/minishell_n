#include "../../headers/minishell.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		result = ft_strdup(s1 ? s1 : s2);
	else
	{
		result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!result)
			return (NULL);
		ft_strlcpy(result, s1, ft_strlen(s1) + 1);
		ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	ft_strdel(&s1);
	return (result);
}

size_t	ft_strcspn(const char *str, const char *charset)
{
	const char *p;
	const char *q;
	size_t count;

	p = str;
	count = 0;
	while (*p != '\0')
	{
		q = charset;
		while (*q != '\0')
		{
			if (*p == *q)
				return (count);
			q++;
		}
		p++;
		count++;
	}
	return (count);
}

// char *strndup(const char *str, size_t n) {
//     char *copy;

//     /* Get the length of the input string */
//     size_t len = strlen(str);

//     /* Allocate memory for the copy */
//     copy = malloc(n + 1);

//     /* Copy the string */
//     strncpy(copy, str, n);
//     copy[n] = '\0';

//     return copy;
// }

// char	*ft_strncpy(char *dest, const char *src, size_t n)
// {
// 	char *ret = dest;

// 	while (n > 0 && *src != '\0')
// 	{
// 		*dest++ = *src++;
// 		n--;
// 	}
// 	while (n > 0)
// 	{
// 		*dest++ = '\0';
// 		n--;
// 	}
// 	return ret;
// }

// //fnct from example
// int	ft_strchars_i(const char *s, char *set)
// {
// 	int				i;

// 	i = 0;
// 	if (!s)
// 		return (-1);
// 	while (s[i] != '\0')
// 	{
// 		if (ft_strchr(set, s[i]))
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }	
