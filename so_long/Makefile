NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	mandatory/check_map.c mandatory/ft_get_next_line_utilis.c mandatory/ft_get_next_line.c \
			mandatory/ft_split.c mandatory/ft_strjoin.c mandatory/ft_strncmp.c mandatory/get_collectibles.c \
			mandatory/handle_error.c mandatory/input.c mandatory/move.c mandatory/name_file.c mandatory/parsing_map.c mandatory/position_player.c \
			mandatory/render_images.c mandatory/parsing2.c mandatory/handle_door.c mandatory/size_character.c mandatory/flood_fill.c mandatory/ft_free.c mandatory/so_long.c mandatory/window.c mandatory/ft_strcmp.c \

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@
	echo "\[\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mBy: mel-badd"
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

