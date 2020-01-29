/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:10:23 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/29 01:00:57 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define RED_VALUE 2
# define GREEN_VALUE 1
# define BLUE_VALUE 0
# define FOV 60
# define RAY_LEN 200
# define SPEED_MOOVE 200
# define ANGLE_MOOVE 100

typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_vecf
{
	double x;
	double y;
}				t_vecf;

typedef struct	s_vect
{
	int x;
	int y;
}				t_vect;

typedef struct	s_rect
{
	t_vect dep;
	t_vect end;
}				t_rect;

typedef struct	s_ray
{
	t_color	color;
	t_vect	map;// int case camera est dessus
	t_vecf	dir;// double vecteur direction de 0 a 1
	t_vecf	pos;// double position de la camera en unite de case
	t_vecf	ray_pos;// double point de depart des rayons en unite de case A VOIR
	t_vecf	ray_dir;// double vecteur direction du rayon de 0 a 1 A VOIR
	t_vecf	side_dist;// distance position de depart - mur en unite de case A VOIR
	t_vecf	delta_dist;// distance entre intersections en unite de case A VOIR
	t_vect	step;// pas a faire pour passer d'une case a l'aure, +1 ou -1 A VOIR
	t_vecf	plane;// vecteur du plan de projection
	int		x;// compteur colonne traitee
	int		y;
	int		camera_x;// position camera par rapport au centre (+ ou -)
	double	perp_wall_dist;// distance corrigee position de depart - mur en unite de case
	int		w;// largeur projection
	int		h;// hauteur projection
	int		hit;// booleen touche un mur ou pas
	int		height_line;// hauteur de la ligne a tracer
	int		draw_start;// pixel min ligne
	int		draw_end;// pixel max ligne
	int		side;// bool orientation mur (1 si mur oriente gauche droite)
}				t_ray;

typedef struct	s_stru
{
	char	**map;
	t_vecf	pos;
	t_vect	orient;
	t_vect	move;
	t_vect	pixel_pos;
	t_vect	res;
	t_color	rgb_sol;
	t_color	rgb_plafond;
	char	*path_nord;
	char	*path_est;
	char	*path_sud;
	char	*path_ouest;
	char	*path_sprite;
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*pixels;
	int		bpp;
	int		sizeline;
	int		endian;
	double	dist_screen;
	t_vect	len_sprite;
	t_vect	map_size;
	double	angle;
	char	begin_pos;
	double	inter_rays;
	t_vect	plane;
	int		w;
	int		h;
}				t_stru;

/* GNL */
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
int		ft_search_nl(char *str);
char	*ft_strjoin_free(char *s1, char *s2, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nb, size_t size);
int		ft_len_line(const char *stock);
int		ft_loop(char **stock, int fd, char *buffer);
int		ft_atoi(const char *nb);

/* LIBFT */
void	*ft_calloc(size_t nb, size_t size);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_path(char *line, int i);

/* CUB3D */
char	*get_path(char *line, int i);
t_color	get_rgb(char *line, int i);
int		parse_cub(int fd, t_stru *stru);
int		check_stru(t_stru *stru);
void	init_stru(t_stru *stru);
char	*strjoin_free_nl(char *s1, char *s2);
int		ft_recursive_power(int nb, int power);
void	res(int i, t_stru *stru, char *line);
int		analyse_line(char *line, t_stru *stru, int i);
double	deg_to_rad(double deg);
double	cos_deg(double deg);
double	sin_deg(double deg);
double	tan_deg(double deg);
t_stru	create_struct(void);
t_stru	*malloc_struct(void);
void	free_struct(t_stru *to_free);
int		convert_colors(t_color color);
t_color	create_color(int r, int b, int g);
void	put_pixel(t_stru *stru, t_color color, int x, int y);
void	draw_rectangle(t_stru *stru, t_rect rect, t_color color);
t_rect	create_rect(int x, int y, int vect_x, int vect_y);
int		cub3d(t_stru *stru);
t_vect	create_vect(int x, int y);
int		check_map(t_stru *stru);
int		check_dep(t_stru *stru);
int		tab_to_matrix(t_stru *stru, char *map);
void	draw_line(t_stru *stru, t_vect pos1, t_vect pos2, t_color color);
void	fill_map(t_stru *stru, char *map, int i);
int		alloc_matrix(char *map, t_stru *stru);
void	departure_angle(t_stru *stru, char *map, int i);
int		error_parsing(void);
void	draw_circle(t_stru *stru, t_vect coord, t_color color, int radius);
double	calc_distance_vector(t_vect a, t_vect b);
void	save_image(void);
void	calcul_dist_screen(t_stru *stru);
void	calcul_map_size(t_stru *stru);
void	calcul_sprite_len(t_stru *stru);
void	calcul_res_rep(t_stru *stru);
double	d_pythagore(t_vect a, t_vect b);
char	*ft_itoa_base(long nb, char *base);
t_vect	mult_vects(t_vect v1, t_vect mult);
t_vect	div_vects(t_vect v1, t_vect div);
t_vect	add_vects(t_vect v1, t_vect v2);
int		draw_vect(t_stru *stru, t_vect vect, int len);
int		key_hook(int keyhook, t_stru *stru);
int		actualise_pos(t_stru *stru);
int		draw_vect(t_stru *stru, t_vect vect, int len);
int		expose_hook(t_stru *stru, int k);
int		loop_hook(t_stru *stru);
int		exit_hook(t_stru *stru);
int		init_mlx(t_stru *stru);
int		rotation(t_stru *stru, int right);
int		clear_window(t_stru *stru);
t_vect	sub_vects(t_vect v1, t_vect v2);
int		check_wall(t_stru *stru, t_vect *to_check);
int		begin_pos(t_stru *stru);
int		ft_printf(char *str, ...);
t_vecf	mult_vectf(t_vecf v1, t_vecf mult);
int		draw_fov(t_stru *stru);
t_vecf	create_vectf(double x, double y);
t_vect	add_vect_and_vectf(t_vect v1, t_vecf v2);
t_vect	mult_vect_and_vecf(t_vect v1, t_vecf mult);
t_vect	horizontal_intersect(t_stru *stru, double angle);
t_vect	vertical_intersect(t_stru *stru, double angle);
void	p_value(int value, char *str);
t_ray	create_ray(t_stru *stru);
int		render(t_stru *stru, int k);

#endif
