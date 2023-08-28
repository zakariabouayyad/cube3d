#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

# define TILE_SIZE 32
# define NUM_COL 14
# define NUM_ROWS 33
# define WINDOW_WIDTH NUM_COL * TILE_SIZE
# define WINDOW_HEIGHT NUM_ROWS * TILE_SIZE

/*     keys     */

# define RIGHT_MOVE 2
# define LEFT_MOVE 0
# define DOWN_MOVE 1
# define UP_MOVE 13
# define RIGHT_ROTATE 124
# define LEFT_ROTATE 123
# define ESC_KEY 53
# define WIN_CLOSE 17

typedef enum s_flags
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOR,
	CEILING,
}	t_flags;

typedef struct s_player
{
	int	x;
	int	y;
	char starting_pos;
}	t_player;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_map {
	/* verify if im using all of this variables */
	t_color		flor_color;
	t_color		ceiling_color;
	char		**map;
	int			row;
	int			col;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename;
	t_player	player;
	// char		starting_pos;
}					t_map;

typedef struct s_data {
	/* verify if im using all of this variables */
	t_map map;
	char **av;
	int fd;
	int i;
	int j;

	void	*img;
	char	*str;
	char	*maps;
	// char	**map;

	void	*mlx;
	void	*mlx_win;
}				t_data;


/*
** cube3d parsing
*/
void	parsing(int ac, t_data *data);
void	extention_and_permission(int ac, t_data *data);
void	check_texture_color(t_data *data);
void	check_texture(char **map, t_data *data);
void	check_color(char **map, t_data *data);
bool	is_whitespace(const char *str);
char	**filter_whitespace_lines(char **lines);
void	remove_whitespace_beginning(char **lines);


/*
**	libft
*/

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* get_next_line */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_line(const char *s);
char	*ft_substr_line(const char *s, unsigned int start, size_t len);
char	*ft_strjoin_line(char *s1, char *s2);
char	*ft_strchr_line(const char *str, int c);

#endif