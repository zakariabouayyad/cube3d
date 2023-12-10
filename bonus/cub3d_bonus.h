/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:11 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 14:19:16 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define TILE_SIZE 32
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define MINI 0.5
# define W_STRIP_WIDTH 1
# define NUM_RAYS WINDOW_WIDTH

# define MINIMAP_WIDTH 200

# define FRAME 16

typedef enum s_flags
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOR,
	CEILING,
}	t_flags;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct doors
{
	int		x;
	int		y;
	double	distance;
}t_doors;

typedef struct player
{
	double	x;
	double	y;
	char	starting_pos;
	double	radius;
	double	move_speed;
	double	rot_speed;
	double	rot_angle;
	double	distance_to_door;
	int		walk;
	int		walk_side;
	int		turn;
	int		mouse_place;
}t_player;

typedef struct ray
{
	double	ray_angle;
	double	delta_x;
	double	delta_y;
	double	hor_wall_x_hit;
	double	hor_wall_y_hit;
	double	ver_wall_x_hit;
	double	ver_wall_y_hit;
	double	final_x_hit;
	double	final_y_hit;
	double	distance;
	double	x_intercept;
	double	y_intercept;
	int		facing_up_down;
	int		facing_right_left;
	int		hitted_v;
	int		hitted_h;
	int		hitted_door_v;
	int		hitted_door_h;
	int		hitted_door;
	int		column;

	bool	is_horz;
	bool	is_vert;
	bool	is_down; 
	bool	is_up;
	bool	is_left;
	bool	is_right;
}t_ray;

typedef struct s_column
{
	double	ray_distance;
	double	ray_distance_fixed;
	double	projection_plane;
	double	w_strip_height;

	double	distance_from_top;

	int		wall_top;
	int		wall_bottom;

	int		offset_x;
	int		offset_y;

}	t_column;

typedef struct s_map {
	char	**map2;
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	flor_color;
	t_color	ceiling_color;

	int		row;
	int		col;
}				t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_data {
	t_img		bullet;
	void		*mlx;
	void		*mlx_win;

	double		fov;
	t_map		map;
	char		**av;
	int			map_lines;
	int			max_line;
	int			mouse_in;
	int			ceiling_color;
	int			flor_color;
	int			fd;
	char		*str;
	char		*maps;
	int			map_width;
	int			map_height;
	int			doors_nbr;
	int			flag;
	int			door_open;

	t_player	player;
	t_ray		*rays;
	t_doors		*doors;

	t_img		minimap;
	t_img		game;

	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_img		door;
	t_column	*column;

	int			frame;
	int			animate;
	int			ammo;
	bool		ammo_out;

	t_img		gun1;
	t_img		gun2;
	t_img		gun3;
	t_img		gun4;
	t_img		gun5;
	t_img		gun6;
	t_img		gun7;
	t_img		gun8;

	t_img		r_01;
	t_img		r_02;
	t_img		r_03;
	t_img		r_04;
	t_img		r_05;
	t_img		r_06;
	t_img		r_07;
	t_img		r_08;
	t_img		r_09;
	t_img		r_10;
	t_img		r_11;
	t_img		r_12;
	t_img		r_13;
	t_img		r_14;

	t_img		n_0;
	t_img		n_1;
	t_img		n_2;
	t_img		n_3;
	t_img		n_4;
	t_img		n_5;
	t_img		n_6;
	t_img		n_7;
	t_img		n_8;
	t_img		n_9;
	t_img		n_10;
}				t_data;

/******** PARSING *********/
void	parsing(t_data *data, char **av);
void	get_color(char *line, t_data *data, t_flags direction);
int		ft_check_name_map(char *map_name);
void	parse_tex_col(t_data *data, char **lines);
void	doors_coord(t_data *data);
void	doors_parsing(t_data *data);
void	free_double(char **list);
bool	is_all_white(const char *str);
void	player_pos(t_data *data);
void	check_chars(char **map);
void	map_size(char *map, t_data *data);
char	**fix_map(char **map, t_data *data);
void	check_map_close(char **map);
void	get_width_height(char **map, t_data *data);
char	**read_six(char *file);
char	**remove_newline6(char **map);
char	**read_map(t_data *data, char *file);
char	**remove_newline(char **map);
void	free_double(char **list);
void	print_error(char *error_msg);
void	init_texture(t_data *data);
int		my_isspace(int c);
void	put_pixel(t_img img, int x, int y, int color);
void	draw_circle2(t_img img, int center_x, int center_y, int radius);
void	dda_line(t_data *data, double x, double y);

/******** LIBFT'CH *********/
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
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *b, size_t n);

/******** ray_casting *********/
int		init_data(t_data	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_min_walls(t_data *data);
void	check_distance(t_data *data, int i);
void	check_if_wall(t_data *data, int flag, int i);
void	one_ray(t_data *data, int i);
double	calculate_distance(double x, double y, double xf, double yf);
void	direction(t_data *data, int i);
double	fix_angle(double ray_angle);
void	player_to_door_dis(t_data *data);

/******** mlx_hooks *********/
int		keys(int keycode, t_data *data);
int		released(int keycode, t_data *data);
void	draw_player(t_data *data);
void	make_minimap(t_data *data);
bool	check_for_wall(t_data *data, double x, double y, int radius);
void	walk_function(t_data *data);
void	render_sprites(t_data *data);
int		get_element_color(t_data *data, double pos_x, double pos_y);
int		game_loop(t_data *data);

/******** wall projection *********/
void	get_x_offset(t_data *data, int i);
void	get_y_offset(t_data *data, int i, int y);
void	project_walls(t_data *data);
int		ft_get_color(int i, t_data *data);

void	put_pixel(t_img img, int x, int y, int color);

void	first_person(t_data *data);
void	reload_frames(t_data *data);
void	ammo_reload(t_data *data);
void	*my_xpm_to_img(void *mlx_ptr, char *filename, int *width, int *height);

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
