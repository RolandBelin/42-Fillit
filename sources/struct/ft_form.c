/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:24:22 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:04:14 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fillit.h>

void		ft_formdel(t_form **form)
{
	if (!form || !*form)
		return ;
	if ((*form)->map)
		ft_astrdel(&(*form)->map, 0);
	free(*form);
	*form = NULL;
}

t_form		*ft_forminit(char **split)
{
	t_form	*form;

	if ((form = (t_form *)malloc(sizeof(t_form))))
	{
		form->map = split;
		form->max_y = 0;
		while (form->map[form->max_y])
			++form->max_y;
		form->max_x = ft_strlen(form->map[0]);
	}
	return (form);
}
