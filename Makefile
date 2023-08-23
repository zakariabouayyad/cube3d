NAME = cub3D

CC = cc

CFLAGS = #-Wall -Wextra -Werror

HEADER = cube3d.h

RM = rm -f

LIBSRC = $(addprefix libft/, ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c get_next_line.c get_next_line_utils.c)

SRC = cube3d.c $(LIBSRC)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re