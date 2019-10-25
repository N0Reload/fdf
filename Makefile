# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:41:30 by lmunoz-q          #+#    #+#              #
#    Updated: 2017/12/02 16:09:58 by lmunoz-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CLIB = -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCFILES = main.c \
		   get_coord.c \
		   get_map.c \
		   create_window.c \
		   wireframe_iso.c \
		   sizetile.c \
		   draw_event.c \
		   zoom.c \
		   heightz.c \
		   trips.c \
		   rgb.c \


INC = inc \
	  libft \
	  minilibx_macos \

DIRS = parsing \
	   printing \
	   event \

INCDIRS = $(addprefix -I,$(INC))

OBJDIR = obj

OBJECTS = $(SRCFILES:%.c=$(OBJDIR)/%.o)

SRCDIRS := $(addprefix src/,$(DIRS))

vpath %.c src $(SRCDIRS)

all: $(NAME)

$(NAME): libft/libft.a minilibx_macos/libmlx.a $(OBJECTS)
	$(CC) $(INCDIRS) $(CLIB) -o $@ $(OBJECTS)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(INCDIRS) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

libft/libft.a: force
	$(MAKE) -w -C libft/

minilibx_macos/libmlx.a: force
	$(MAKE) -w -C minilibx_macos/

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -w -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -w -C libft/ fclean

re: fclean all

force:
	true

.PHONY: all clean fclean re
