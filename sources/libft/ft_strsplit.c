/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 03:58:48 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 03:00:02 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static size_t	ft_splitlen(const char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (str && *str)
	{
		while (str[i])
		{
			while (str[i] == c && str[i])
				++i;
			if (str[i] != c && str[i])
				++count;
			while (str[i] != c && str[i])
				++i;
		}
	}
	return (count);
}

static char	*ft_localstrndup(const char *str, size_t n)
{
	char	*ret;
	size_t	i;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * (n + 1))))
	{
		while (str[i] && i < n)
		{
			ret[i] = str[i];
			++i;
		}
		while (i < n)
		{
			ret[i] = '\0';
			++i;
		}
		ret[i] = '\0';
	}
	return (ret);
}

char		**ft_strsplit(const char *str, char c)
{
	size_t	index;
	size_t	len;
	char	**ret;

	len = ft_splitlen(str, c);
	index = 0;
	if (!len || !(ret = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (*str && !(len = 0))
	{
		while (*str == c && *str)
			++str;
		while (str[len] != c && str[len])
			++len;
		if (!len || !(ret[index] = ft_localstrndup(str, len)))
			break;
		++index;
		str += len;
	}
	ret[index] = NULL;
	return (ret);
}
