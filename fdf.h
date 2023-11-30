
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
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_fdf
{
	float	z;
	int color;
}	t_fdf;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	width;
	int	height;
	int	max;
	int	color;
	int	prespective;
	int	hor;
	int	hey;
	float	angle;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	double	zoom;
	int	x;
	int	y;
	double	u;
	double	v;
	float	z;
	float	z1;
	double	x_step;
	double	y_step;
	t_fdf	**map;
	t_img		img;
}	t_data;


///////////////////////////////
//       Map Functions       //
///////////////////////////////

void	creat_map(char *file, t_data *data);
void	map_size(char *file, t_data *data);
void	ft_write_map(t_data *data);
void	fill_map(char *file, t_data *data);
void	fill_matrix(t_data *data, int x, int y, char *splited);
int	atoi_base(char *str);
int	check_for_colors(char *str);

///////////////////////////////
//     Display Functions     //
///////////////////////////////

void	open_window(t_data *data);
int	init_window(t_data *data);
int	render_map(t_data *data);
float	positive(float n);
float	max_step(float x_step, float y_step);
void	bresenhaim(t_data *data, double x1, double y1);
void	bresenhaim_2d(t_data *data, double x1, double y1);
void	isometric(double *x, double *y, float *z, t_data *data);
int	build_img(t_data *data);
void	zoom(double *x, double *y, t_data *data);
void	map_move(double *x, double *y, t_data *data);
int	change_zoom(int keysym, t_data *data);
void	colors_change(t_data *data);
void	map_par(t_data *data);
void	map_impar(t_data *data);
void	map_par_2d(t_data *data);
void	map_impar_2d(t_data *data);
int	menu_render(t_data *data);
int	menu_background_render(t_data *data);

///////////////////////////////
//     Handlers Functions    //
///////////////////////////////

int	handle_keypress(int keysym, t_data *data);
int	handle_close(t_data *data);
int	move_handle(int keysym, t_data *data);
int	mouse_input(int	keycode, int x, int y, t_data *data);
int	angle_handle(int keysym, t_data *data);
int	z_handle(int keysym, t_data *data);
void	rotate_x_axis(t_data *data, double *y, float *z);
void	rotate_y_axis(t_data *data, double *x, float *z);
void	rotate_z_axis(t_data *data, double *x, double *y);

///////////////////////////////
//       Keys Functions      //
///////////////////////////////

int	decrease_z(t_data *data);
int	increase_z(t_data *data);
int	default_img(t_data *data);

///////////////////////////////
//       Free functions      //
///////////////////////////////

void	ft_free_map(t_data *data);
void    ft_free_splited(char **splited);

#endif
