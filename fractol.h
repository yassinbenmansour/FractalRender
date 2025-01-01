/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:33:30 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/01 04:38:59 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
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
	int		num_ieration; // Nombre d'itérations effectuées pour un point.
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
	int		max_it;
	int		color;
	int		color_code;
	int		julia;
	int		julia_move;
}            t_fractol;


void	ft_instructions(void);
int		ft_close(t_fractol *fractol);
int		ft_atoi(char *num);
double	ft_map(int in, double min, double max);
void	ft_init(t_fractol *fractol, int number);
double	ft_atof(char *str, double res);



#endif