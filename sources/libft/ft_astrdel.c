/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 01:43:36 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:33:12 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		ft_astrdel(char ***ap, int size)
{
	char	**split;
	int	i;

	i = 0;
	if (ap && *ap)
	{
		split = *ap;
		if (!size)
		{
			while (split[i])
			{
				ft_strdel(&split[i]);
				++i;
			}
		}
		while (i < size)
		{
			ft_strdel(&split[i]);
			++i;
		}
		free(*ap);
		*ap = NULL;
	}
}
