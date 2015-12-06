/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 22:13:11 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:09:12 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_closeexit(t_fillit *fillit, int fd)
{
	close(fd);
	ft_fillitdel(&fillit, 1);
}

static char	ft_buffer_checkcount(const char *buffer, size_t len)
{
	char	dieses;
	char	dot;
	size_t	i;

	i = 0;
	dot = 0;
	dieses = 0;
	if (len < 20 || len > 21 || buffer[0] == '\n')
		return (0);
	while (i < len)
	{
		if (buffer[i] == '#')
			++dieses;
		else if (buffer[i] == '.')
			++dot;
		++i;
	}
	return ((dieses != 4 || dot != 12) ? 0 : 1);
}

static char	ft_buffer_checkform(const char *buffer)
{
	char	linelen;
	size_t	i;
	size_t	len;

	linelen = 0;
	len = ft_strlen(buffer);
	i = 0;
	while (i <= len)
	{
		++linelen;
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			if ((linelen != 5) &&
				((i == 20 && i == 21) && linelen != 1))
				return (0);
			linelen = 0;
		}
		else if (buffer[i] != '.' && buffer[i] != '#')
			return (0);
		++i;
	}
	return (ft_buffer_checkcount(buffer, len));
}

void		ft_fileload(t_fillit *fillit, int fd)
{
	char	buffer[21];
	size_t	last;
	size_t	reallast;

	reallast = 0;
	last = 0;
	if (fd == -1)
		ft_fillitdel(&fillit, 1);
	while ((last = read(fd, buffer, 21)))
	{
		reallast = last;
		if ((buffer[20] != '\n' && buffer[20] != '\0') ||
			!(ft_buffer_checkform(buffer)))
			ft_closeexit(fillit, fd);
		if (!ft_buffertotype(fillit, buffer))
			ft_closeexit(fillit, fd);
	}
	if (reallast > 20)
		ft_closeexit(fillit, fd);
	close(fd);
}
