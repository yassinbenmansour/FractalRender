/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:50:45 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/10 10:14:46 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mouse_zoom(t_fractol *fractol, int button, int x, int y)
{
	double	new_ox;
	double	new_oy;

	new_ox = ft_map(x, fractol->ox - (fractol->zoom * 0.128), fractol->ox
			+ (fractol->zoom * 0.128));
	new_oy = ft_map(y, fractol->oy - (fractol->zoom * 0.128), fractol->oy
			+ (fractol->zoom * 0.128));
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
