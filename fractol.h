/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:33:30 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/02 06:55:07 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"

# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_var
{
	double	a;      // Partie réelle de la coordonnée complexe actuelle.
	double	b;      // Partie imaginaire de la coordonnée complexe actuelle.
	double	aa;     // Carré de la partie réelle (optimisation pour éviter de recalculer plusieurs fois).
	double	bb;     // Carré de la partie imaginaire (optimisation).
	double	a_r;    // Partie réelle de la constante utilisée dans Julia (ou d'autres fractales).
	double	b_r;    // Partie imaginaire de la constante utilisée dans Julia (ou d'autres fractales).
	int		num_iteration; // Nombre d'itérations effectuées pour un point.
} t_var;

typedef struct s_fractol
{
    void	*cnx;
	void	*window;
	t_image	image;
	t_var	var;
	double	zoom;
	double	ox;
	double	oy;
	int		max_iteration;
	int		color;
	int		color_code;
	int		julia;
}            t_fractol;


void	ft_instructions(void);
int		ft_close(t_fractol *fractol);
int		ft_atoi(char *num);
double	ft_map(int in, double min, double max);
void	ft_init(t_fractol *fractol, int number);
double	ft_atof(char *str, double res);
void	ft_pre_cal(t_fractol *fractol, int x, int y);
void	ft_calculater(t_fractol *fractol);
void	ft_mlx_pixel_put(t_fractol fractol, int x, int y, int color);
void	ft_draw(t_fractol fractol);
int	ft_key_hook(int keycode, void *param);
void	ft_get_color(t_fractol *fractol);
int	ft_mouse_hook(int button, int x, int y, void *param);
int			ft_mouse_hook(int button, int x, int y, void *param);
void	julia_args(char **av);



#endif