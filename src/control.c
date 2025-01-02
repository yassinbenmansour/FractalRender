/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:47:10 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/02 07:31:23 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

//get_color function to get the color of each pixel !
void	ft_get_color(t_fractol *fractol)
{
	fractol->color_code++;
	if (fractol->color_code == 8)
		fractol->color_code = 0;
	if (fractol->color_code == 0)
		fractol->color = 0xff0801;
	else if (fractol->color_code == 1)
		fractol->color = 0xfff600;
	else if (fractol->color_code == 2)
		fractol->color = 0x18ff00;
	else if (fractol->color_code == 3)
		fractol->color = 0xf4f4f5;
	else if (fractol->color_code == 4)
		fractol->color = 0xb0ffd9;
	else if (fractol->color_code == 5)
		fractol->color = 0xffffd9;
	else if (fractol->color_code == 6)
		fractol->color = 0xFFFCA7;
	else if (fractol->color_code == 7)
		fractol->color = 0xf1f1e1;
}

//ft_key_hook function to handle the key events !
//keycode == 53 || keycode == 12 to exit the program !
//keycode == 126 || keycode == 125 || keycode == 124 ||
//keycode == 123 to move the fractal !
int	ft_key_hook(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 126)
		fractol->oy -= fractol->zoom / 10;
	else if (keycode == 125)
		fractol->oy += fractol->zoom / 10;
	else if (keycode == 124)
		fractol->ox += fractol->zoom / 10;
	else if (keycode == 123)
		fractol->ox -= fractol->zoom / 10;
	if (keycode == 35 || keycode == 15 || keycode == 45 || keycode == 6
		|| keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_draw(*fractol);
	return (0);
}

//ft_mouse_zoom function to handle the mouse events !
//button == 5 to zoom in ! button == 4 to zoom out !
//x and y are the coordinates of the mouse !
//new_ox and new_oy are the new coordinates of the mouse !
//we use ft_map function to map the coordinates of the mouse !
void	ft_mouse_zoom(t_fractol *fractol, int button, int x, int y)
{
	double	new_ox;
	double	new_oy;

	new_ox = ft_map(x, fractol->ox - (fractol->zoom * 0.128), fractol->ox + (fractol->zoom
				* 0.128));
	new_oy = ft_map(y, fractol->oy - (fractol->zoom * 0.128), fractol->oy + (fractol->zoom
				* 0.128));
	fractol->ox = new_ox;
	fractol->oy = new_oy;
	if (button == 5)
		fractol->zoom -= fractol->zoom * 0.1;
	else if (button == 4)
		fractol->zoom += fractol->zoom * 0.1;
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (button != 1 && button != 2)
	{
		ft_mouse_zoom(fractol, button, x, y);
		ft_draw(*fractol);
	}
	
	return (0);
}

