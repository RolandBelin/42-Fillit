/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffertotype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 00:53:51 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:08:57 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_split_right(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(split[0]) - 1;
	while (split[i] && split[i][j] == '.')
		++i;
	if (split[i])
		return ;
	i = 0;
	while (split[i])
	{
		split[i][j] = '\0';
		++i;
	}
	ft_split_right(split);
}

static void	ft_split_up(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i][j] && split[i][j] == '.')
		++j;
	if (split[i][j])
		return ;
	while (split[i])
	{
		split[i] = split[i + 1];
		++i;
	}
	ft_split_up(split);
}

static void	ft_split_left(char **split)
{
	int	i;

	i = 0;
	while (split[i] && split[i][0] == '.')
		++i;
	if (split[i])
		return ;
	i = 0;
	while (split[i])
	{
		split[i] = ft_strcpy(split[i], split[i] + 1);
		++i;
	}
	ft_split_left(split);
}

static void	ft_split_down(char **split)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (split[i])
		++i;
	i = i - 1;
	while (split[i][j] && split[i][j] == '.')
		++j;
	if (split[i][j])
		return ;
	ft_strdel(&split[i]);
	ft_split_down(split);
}

char		ft_buffertotype(t_fillit *fillit, const char *buffer)
{
	char	**split;
	int	i;

	i = 0;
	if ((split = ft_strsplit(buffer, '\n')))
	{
		ft_split_down(split);
		ft_split_up(split);
		ft_split_right(split);
		ft_split_left(split);
		while (split[i])
			++i;
		if ((i * ft_strlen(split[0])) > 6)
		{
			ft_astrdel(&split, i);
			return (0);
		}
		ft_fillitaddtype(fillit, split);
		return (1);
	}
	return (0);
}
