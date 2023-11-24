
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

# define WIDTH 1020
# define HEIGHT 800

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
	float	right;
	float	left;
	float	angle;
	float	zoom;
	float	x;
	float	y;
	int	**map;
	t_img		img;
}	t_data;

///////////////////////////////
//       Map Functions       //
///////////////////////////////

void	creat_map(char *file, t_data *data);
void    ft_free_splited(char **splited);
int	height_size(t_data *data);
int	size_width(char *file, t_data *data);
void	ft_write_map(t_data *data);
void	fill_map(char *file, t_data *data);
void	ft_free_map(t_data *data);

///////////////////////////////
//     Display Functions     //
///////////////////////////////

int	init_window(t_data *data);
int	render_map(t_data *data);
void	open_window(t_data *data);
int	handle_keypress(int keysym, t_data *data);
int	render(t_data *data);
int	handle_close(t_data *data);
int	change_zoom(int keysym, t_data *data);
float	positive(float n);
float	MAX(float x_step, float y_step);
void	bresenhaim(t_data *data, float x1, float y1);
void	isometric(float *x, float *y, float *z, t_data *data);
void	zoom(float *x, float *y, t_data *data);
void	map_move(float *x, float *y, t_data *data);
void	increase_z(t_data *data);
void	decrease_z(t_data *data);
int	my_mlx_pixel_put(t_data *data, float x, float y, int color);

#endif
