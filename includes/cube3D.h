/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:03:07 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/09 16:03:01 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "../libft/libft.h"

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define PI 3.14159265
# define ROT_SPEED 0.20

typedef struct s_pos
{
	double				height;
	double				width;
	double				posx;
	double				posy;
	//double				real_x;
	//double				real_y;
	double				dirX;
	double				dirY;
	double				rot;
	int					xmax;
	int					ymax;
	int					x;
	int					y;
}					t_pos;

typedef struct s_texture
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_texture;

typedef struct s_imgs
{
	struct s_texture	wall;
	struct s_texture	sol;
	struct s_texture	player;
	struct s_texture	air;
	struct s_texture	back;
	struct s_texture	ray_cam;
	struct s_texture	rayon;
	char				*n_wall;
	char				*e_wall;
	char				*s_wall;
	char				*w_wall;
	char				*c_wall;
	char				*f_wall;
}					t_imgs;

typedef struct s_map
{
	char			content;
	int				x;
	int				y;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct s_data
{
	void				*mlx;
	void				*mlx_win;
	int					parse_status;
	double				x;
	double				y;
	double				*len_rayons;  // tableau de longueur de chaque rayon jusqu'au premier mur qu'il rencontre
	int					**tab_walls;  // tableau de tableau des coordonnes de chaque mur, va servir pour verifier l'intersection du 1er mur avec l'equation de la droite du rayon
	struct s_pos		pos;
	struct s_imgs		img;
	struct s_map		*map;
}						t_data;

//MAIN
int		init_arg(t_data *data, char *file);
void	init_data(t_data *data);
void	init_dir(t_data *data, char content);
void	init_game(t_data *data);

//WALL
int		init_walls(t_data *data, char *file);
int		add_img(t_data *data, char **arg, int status);
int		valid_str(char *str);

//MAP
void	init_map(t_data *data, char *file);
void	fill_map(t_map **map, char content, int x, int y);
t_map	*last_map(t_map **map);
void	print_map(t_map *map);

//PARSER
int		parse_map(t_data *data);
int		valid_char(t_data *data);
int		valid_color(char *str);
int		closed_map(t_data *data);
t_map	*new_map(t_data *data);

//PARSER_UTILS
char	content_up(t_map *map);
char	content_down(t_data *data, t_map *map);
int		ft_atoi_color(char *str);

//IMG
void	init_img(t_data *data);
void	render_background(t_data *data, t_texture *img, int color);
void	render_ofback(t_texture *img, int color);
void	img_pix_put(t_texture *img, int x, int y, int color);

//DRAW
int		first_draw(t_data *data);
int		draw(t_data *data, double x, double y);
void	print_square(t_data *data, int x, int y, int color);

//KEY
int		press_key(int key, t_data *data);
int		walled(t_data *data, int x, int y);
int		check_up_left_wall(t_data *data, int x, int y);
int		check_down_left_wall(t_data *data, int x, int y);
int		check_up_right_wall(t_data *data, int x, int y);
int		check_down_right_wall(t_data *data, int x, int y);

//MOVES
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_d(t_data *data);
void	move_s(t_data *data);

//RAYONS
void	put_ray_cam(t_data *data);
void	modify_rot(t_data *data, int key);
void	put_rayons(t_data *data);
void	trace_rayon(t_data *data, double dirX, double dirY, int j);
void	create_tab_walls(t_data *data);
void	fill_tab_walls(t_data *data);
void	calcul_len_rayons(t_data *data);
double	len_collision(t_data *data, double dirX, double dirY);
int		wall_here(t_data *data, int x, int y);
//void	affich_tab_walls(t_data *data);  // pour debbuger

//FREE
int		free_all(t_data *data);
void	free_map(t_map **map);
void	free_img(t_imgs *img);
void	free_tab(char **str);

#endif