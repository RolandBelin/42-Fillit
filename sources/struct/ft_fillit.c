/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:40:10 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:04:46 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		ft_fillitaddtype(t_fillit *fillit, char **split)
{
	int	index;

	index = fillit->totaltype;
	if (index == 26)
		ft_fillitdel(&fillit, 1);
	if (!(fillit->alltype[index] = ft_typeinit(index)) ||
		!(fillit->alltype[index]->form = ft_forminit(split)))
		ft_fillitdel(&fillit, 1);
	fillit->totaltype++;
}

void		ft_fillitdel(t_fillit **af, char e)
{
	int	i;

	i = 0;
	if (!af || !*af)
		return ;
	if ((*af)->alltype)
	{
		while (i < (*af)->totaltype)
		{
			ft_formdel(&(*af)->alltype[i]->form);
			ft_typedel(&(*af)->alltype[i]);
			++i;
		}
		free((*af)->alltype);
		(*af)->alltype = NULL;
	}
	free(*af);
	*af = NULL;
	if (e)
		ft_putendl("error");
	exit(0);
}

t_fillit	*ft_fillitinit(void)
{
	t_fillit	*fillit;

	if ((fillit = (t_fillit *)malloc(sizeof(t_fillit))))
	{
		fillit->alltype = (t_type **)malloc(sizeof(t_type *) * 26);
		if (fillit->alltype)
		{
			fillit->totaltype = 0;
			fillit->bruteforce_hit = 0;
		}
		else
			ft_fillitdel(&fillit, 1);
	}
	if (!fillit)
	{
		ft_putendl("error");
		exit(1);
	}
	return (fillit);
}
