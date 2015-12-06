/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 22:42:52 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 01:39:53 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		ft_putendl(const char *str)
{
	char	c;
	size_t	i;

	i = 0;
	c = '\n';
	while (str[i])
		++i;
	write(1, str, i);
	write(1, &c, 1);
}