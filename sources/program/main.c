/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:09:46 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:47:00 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int ac, char **av)
{
	int		i;
	t_fillit	*fillit;

	i = 0;
	fillit = NULL;
	if (ac > 1)
	{
		fillit = ft_fillitinit();
		ft_fileload(fillit, open(av[1], O_RDONLY));
		ft_checkform(fillit);
		ft_bruteforce(fillit);
		while (i < fillit->release->size)
		{
			ft_putendl(fillit->release->byte[i]);
			++i;
		}
		ft_fillitdel(&fillit, 0);
	}
	else
		ft_putendl("error");
	return (0);
}
