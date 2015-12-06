#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/04 11:06:12 by rbelin            #+#    #+#             *#
#*   Updated: 2015/12/06 03:06:13 by rbelin           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=		fillit
CC=		gcc
CLFAGS=		-Wall -Wextra -Werror

DIR_INCLUDE=	./includes/
DIR_SOURCES=	./sources/
DIR_OBJECTS=	./objects/

FILE_SOURCE=	$(shell find $(DIR_SOURCES)*/*.c -type f)
FILE_OBJECT=	$(shell find ./*.o -type f)

all: $(NAME)

$(NAME): MAKE EXEC

MAKE:
	$(CC) -o $(NAME) $(CLFAGS) -I$(DIR_INCLUDE) $(FILE_SOURCE)

EXEC:
	
