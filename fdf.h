
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
	float	angle_x;
	float	angle_y;
	float	zoom;
	int	x;
	int	y;
	float	u;
	float	v;
	float	z;
	float	z1;
	float	x_step;
	float	y_step;
	float	**map;
	t_img		img;
}	t_data;

///////////////////////////////
//       Map Functions       //
///////////////////////////////

void	creat_map(char *file, t_data *data);
void    ft_free_splited(char **splited);
void	size_height(char *file, t_data *data);
void	size_width(char *file, t_data *data);
void	ft_write_map(t_data *data);
void	fill_map(char *file, t_data *data);
void	ft_free_map(t_data *data);

///////////////////////////////
//     Display Functions     //
///////////////////////////////

int	init_window(t_data *data);
int	render_map(t_data *data);
void	open_window(t_data *data);
float	positive(float n);
float	max_step(float x_step, float y_step);
void	bresenhaim(t_data *data, float x1, float y1);
void	bresenhaim_2d(t_data *data, float x1, float y1);
void	isometric(float *x, float *y, float *z, t_data *data);
int	build_img(t_data *data);
void	zoom(float *x, float *y, t_data *data);
void	map_move(float *x, float *y, t_data *data);
int	change_zoom(int keysym, t_data *data);
void	colors_change(t_data *data);

///////////////////////////////
//     Handlers Functions    //
///////////////////////////////

int	handle_keypress(int keysym, t_data *data);
int	handle_close(t_data *data);
int	move_handle(int keysym, t_data *data);
int	mouse_input(int	keycode, int x, int y, t_data *data);
int	angle_handle(int keysym, t_data *data);
int	z_handle(int keysym, t_data *data);
int	decrease_z(t_data *data);
int	increase_z(t_data *data);
int	default_img(t_data *data);
void	map_par(t_data *data);
void	map_impar(t_data *data);
void	map_par_2d(t_data *data);
void	map_impar_2d(t_data *data);


#endif
