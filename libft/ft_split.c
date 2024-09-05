/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 02:14:11 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/09/04 22:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	word_count(const char *str, char sep)
// {
// 	size_t	word;
// 	size_t	res;

// 	res = 0;
// 	word = 0;
// 	while (*str)
// 	{
// 		if (*str == sep)
// 			word = 0;
// 		else if (!word)
// 		{
// 			word = 1;
// 			res ++;
// 		}
// 		str++;
// 	}
// 	return (res);
// }

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

// static void	copyelements(char *res, const char *start, char const *s, size_t *i)
// {
// 	size_t	j;
// 	size_t	tmp;

// 	j = 0;
// 	tmp = s - start;
// 	while (j < tmp)
// 	{
// 		res[j] = start[j];
// 		j++;
// 	}
// 	res[j] = '\0';
// 	(*i)++;
// }

// int	ft_checck(char **res)
// {
// 	if (!res)
// 	{
// 		ft_free(res);
// 		return (0);
// 	}
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t		i;
// 	const char	*start;
// 	char		**res;

// 	i = 0;
// 	res = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
// 	if (!s || !res)
// 		return (NULL);
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s)
// 		{
// 			start = s;
// 			while (*s && *s != c)
// 				s++;
// 			res[i] = (char *)malloc((s - start + 1) * sizeof(char));
// 			if (ft_checck(res) == 0)
// 				return (NULL);
// 			copyelements(res[i], start, s, &i);
// 		}
// 	}
// 	res[i] = NULL;
// 	return (res);
// }

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	word_length(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**f(char const *s, char c, char **result, int words_count)
{
	int	i;
	int	j;
	int	w_len;

	while (*s == c)
		s++;
	i = -1;
	while (++i < words_count)
	{
		while (*s == c)
			s++;
		j = 0;
		w_len = word_length(s, c);
		result[i] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!(result[i]))
			return (NULL);
		while (j < w_len)
		{
			result[i][j] = *s;
			s++;
			j++;
		}
		result[i][j] = '\0';
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wcount;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!(result))
		return (NULL);
	result = f(s, c, result, wcount);
	result[wcount] = NULL;
	return (result);
}
