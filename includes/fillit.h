/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:37:17 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:59:01 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define D_BRUTEFORCE_HIT 500000 / fillit->totaltype

typedef struct		s_form
{
	char		**map;
	int		max_x;
	int		max_y;
	int		map_mx;
	int		map_my;
}			t_form;

typedef struct		s_type
{
	char		printed;
	int		idtype;
	t_form		*form;
	char		letter;
	int		pos_x;
	int		pos_y;
}			t_type;

typedef struct		s_map
{
	char		**byte;
	int		size;
}			t_map;

typedef struct		s_fillit
{
	struct s_type	**alltype;
	int		totaltype;
	int		totalprinted;
	int		bruteforce_hit;
	struct s_map	*beta;
	struct s_map	*release;
}			t_fillit;

/* Libft functions */
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			**ft_strsplit(const char *str, char c);
void			ft_putendl(const char *str);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **ap);
void			ft_astrdel(char ***ap, int size);

/* File functions */
void			ft_fileload(t_fillit *fillit, int fd);
char			ft_buffertotype(t_fillit *fillit, const char *buffer);

/* Form functions */
t_form			*ft_forminit(char **split);
void			ft_formdel(t_form **form);
void			ft_checkform(t_fillit *fillit);

/* Type functions */
t_type			*ft_typeinit(int idtype);
void			ft_typedel(t_type **type);

/* Fillit functions */
t_fillit		*ft_fillitinit(void);

void			ft_fillitdel(t_fillit **af, char e);
void			ft_fillitaddtype(t_fillit *fillit, char **split);

/* Map functions */
t_map			*ft_mapinit(int size);
t_map			*ft_mapdup(t_map *map);
void			ft_mapdel(t_map **map);
char			ft_mapplace(t_map *map, t_type *type, int x, int y);
void			ft_mapremove(t_map *map, t_type *type);

/* Bruteforce */
char			ft_bruteforceelem(t_fillit *fillit, int *id);
void			ft_bruteforce(t_fillit *fillit);

#endif
