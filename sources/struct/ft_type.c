/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:23:57 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:04:21 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		ft_typedel(t_type **type)
{
	if (type && *type)
	{
		free(*type);
		*type = NULL;
	}
}

t_type		*ft_typeinit(int idtype)
{
	t_type	*type;

	if ((type = (t_type *)malloc(sizeof(t_type))))
	{
		type->idtype = idtype;
		type->letter = 'A' + idtype;
		type->pos_x = -1;
		type->pos_y = -1;
	}
	return (type);
}
