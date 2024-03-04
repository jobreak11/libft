/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:02:52 by gyeepach          #+#    #+#             */
/*   Updated: 2024/03/04 09:00:05 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	wordcount(const char *s, char c)
{
	size_t	count;


	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	free_space(char **res, int position, size_t buffer)
{
	int	i;

	i = 0;
	res[position] = malloc(buffer);
	if (res[position] == NULL)
	{
		while (i < position)
			free(res[i++]);
		free(res);
		return (1);
	}
	return (0);
}

static int	put_word(char **res, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (free_space(res, i, len + 1))
				return (1);
			ft_strlcpy(res[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**res;

	if (!s)
		return (0);
	words_count = wordcount(s, c);
	res = malloc((words_count + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[words_count] = NULL;
	if (put_word(res, s, c))
		return (NULL);
	return (res);
}
// #include <stdio.h>

// int main()
// {
//     char **a;

//     a = "asd,sda,sf";
//     printf("%s\n", ft_split(a, ','));
// }

// int	main()
// {
// 	char	*s = "   Hello there, dude!!";
// 	char	**v = ft_split(s, ' ');

// 	while (*v)
// 		printf("%s\n", *v++);
// }
