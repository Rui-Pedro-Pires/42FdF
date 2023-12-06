/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:34:56 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 14:03:42 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./include/Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	float	z;
	int		color;
}	t_fdf;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	z;
	float	z1;
	double	zoom;
	double	u;
	double	v;
	double	x_step;
	double	y_step;
	int		width;
	int		height;
	int		max;
	int		color_default;
	int		menu_color;
	int		color_save;
	int		add_color;
	int		hor;
	int		hey;
	int		button;
	int		max_z;
	int		min_z;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	t_fdf	**map;
	t_img	img;
}	t_data;

///////////////////////////////
//       Map Functions       //
///////////////////////////////

void	creat_map(char *file, t_data *data);
void	map_size(char *file, t_data *data);
void	ft_write_map(t_data *data);
void	fill_map(char *file, t_data *data);
void	fill_matrix(t_data *data, int x, int y, char *splited);
void	ft_read_error(char *line);
void	ft_open_error(int fd);

///////////////////////////////
//       Init Functions      //
///////////////////////////////

int		init_window(t_data *data);
void	open_window(t_data *data);

///////////////////////////////
//      Render Functions     //
///////////////////////////////

int		render_map(t_data *data);
int		menu_render(t_data *data);
int		menu_background_render(t_data *data);
void	render_strings1(t_data *data);
void	render_strings2(t_data *data);
void	map_par(t_data *data);
void	map_impar(t_data *data);
void	map_misto1(t_data *data);
void	map_misto2(t_data *data);

///////////////////////////////
//    Bresenham Functions    //
///////////////////////////////

int		build_img(t_data *data);
float	positive(float n);
float	max_step(float x_step, float y_step);
void	bresenham(t_data *data, double x1, double y1);

///////////////////////////////
//     Handlers Functions    //
///////////////////////////////

int		handle_keypress(int keysym, t_data *data);
int		handle_close(t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		handle_mouse_down(int button, int x, int y, t_data *data);
int		handle_mouse_up(int button, int x, int y, t_data *data);
int		move_handle(int keysym, t_data *data);
int		angle_handle(int keysym, t_data *data);
int		projection_handle(int keysym, t_data *data);
int		z_handle(int keysym, t_data *data);

///////////////////////////////
//      Colors Functions     //
///////////////////////////////

int		atoi_base(char *str);
int		check_for_colors(char *str);
int		get_pos(char c);
int		color_handler(int keysym, t_data *data);
void	colors_change(t_data *data);
void	colors1(t_data *data);
void	colors2(t_data *data);
void	colors3(t_data *data);
void	colors4(t_data *data);
void	get_max_z(t_data *data);
void	get_min_z(t_data *data);

////////////////////////////////////////////////////
//     Rotation / Translation / zoom Functions    //
////////////////////////////////////////////////////

void	rotation(t_data *data, double *x1, double *y1);
void	rotate_x_axis(t_data *data, double *y, float *z);
void	rotate_y_axis(t_data *data, double *x, float *z);
void	rotate_z_axis(t_data *data, double *x, double *y);
void	zoom(double *x, double *y, t_data *data);
void	map_move(double *x, double *y, t_data *data);

///////////////////////////////
//       Keys Functions      //
///////////////////////////////

int		decrease_z(t_data *data);
int		increase_z(t_data *data);

///////////////////////////////
//       Free functions      //
///////////////////////////////

void	ft_free_map(t_data *data);
void	ft_free_splited(char **splited);

#endif
