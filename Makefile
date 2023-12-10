
NAME = cub3D

BNAME = cub3D_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror #-Ofast #-g

HEADER = ./mandatory/cub3d.h

HEADER_BONUS = ./bonus/cub3d_bonus.h

RM = rm -f

LIBSRC = $(addprefix mandatory/libft/, ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_calloc.c ft_bzero.c get_next_line.c get_next_line_utils.c)

BLIBSRC = $(addprefix bonus/libft/, ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_calloc.c ft_bzero.c get_next_line.c get_next_line_utils.c)

PARSING = $(addprefix mandatory/parsing/, parsing.c parsing_color.c parsing_texture.c more_parsing.c parsing_again.c utils.c)

BPARSING = $(addprefix bonus/parsing/, parsing_bonus.c parsing_color_bonus.c parsing_texture_bonus.c more_parsing_bonus.c door_parsing_bonus.c parsing_again_bonus.c utils_bonus.c)

RAYCASTING = $(addprefix mandatory/ray_casting/, init_data.c mlx_hooks.c game_loop.c drawing.c check_if_wall.c check_distance.c hor_ver_cast.c more_game_loop.c direction.c)

BRAYCASTING = $(addprefix bonus/ray_casting/, init_data_bonus.c mlx_hooks_bonus.c game_loop_bonus.c drawing_bonus.c check_if_wall_bonus.c check_distance_bonus.c hor_ver_cast_bonus.c more_game_loop_bonus.c direction_bonus.c)

REST = $(addprefix mandatory/, cub3d.c wall_projection.c initialize.c more_utils.c get_color_tex.c more_wall_projection.c)

BREST = $(addprefix bonus/, cub3d_bonus.c wall_projection_bonus.c gun_animation_bonus.c initialize_bonus.c more_utils_bonus.c get_color_tex_bonus.c more_wall_projection_bonus.c)

SRC = $(REST) $(PARSING) $(LIBSRC) $(RAYCASTING)

BSRC = $(BREST) $(BPARSING) $(BLIBSRC) $(BRAYCASTING)

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus : $(BNAME)

$(BNAME) : $(BOBJ)
	$(CC) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

bonus/%.o : bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	$(RM) $(NAME) $(BNAME)

re : fclean all

.PHONY : all clean fclean re
