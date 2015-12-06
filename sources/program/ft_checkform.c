/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:13:58 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 03:03:40 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_splash(t_form *form, int y, int x)
{
	form->map[y][x] = '?';
	if (x + 1 < form->max_x && form->map[y][x + 1] == '#')
		ft_splash(form, y, x + 1);
	if (x > 0 && form->map[y][x - 1] == '#')
		ft_splash(form, y, x - 1);
	if (y + 1 < form->max_y && form->map[y + 1][x] == '#')
		ft_splash(form, y + 1, x);
	if (y > 0 && form->map[y - 1][x] == '#')
		ft_splash(form, y - 1, x);
}

static char	ft_isvalidandreset(t_form *form, char old, char new)
{
	int	i;
	int	j;

	i = 0;
	while (form->map[i])
	{
		j = 0;
		while (form->map[i][j])
		{
			if (form->map[i][j] == old)
				return (0);
			else if (form->map[i][j] == new)
				form->map[i][j] = old;
			++j;
		}
		++i;
	}
	return (1);
}

void		ft_checkform(t_fillit *fillit)
{
	t_form	*form;
	int	i;
	int	x;

	i = 0;
	while (i < fillit->totaltype)
	{
		x = 0;
		form = fillit->alltype[i]->form;
		while (form->map[0][x] != '#')
			++x;
		ft_splash(form, 0, x);
		if (!ft_isvalidandreset(form, '#', '?'))
			ft_fillitdel(&fillit, 1);
		++i;
	}
}
