/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:39:57 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 01:40:50 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char		*ft_strdup(const char *str)
{
	size_t	i;
	char	*ret;
	
	if ((ret = (char *)malloc(sizeof(char) * ((i = ft_strlen(str)) + 1))))
	{
		ret[i] = '\0';
		while (i--)
			ret[i] = str[i];
	}
	return (ret);
}
