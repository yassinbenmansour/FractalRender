/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:46:23 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/01 04:40:22 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

char	*ft_get_title(int fractol)
{
	if (fractol == 1)
		return ("FRACTOLL - Mandelbrot by yabenman");
	else  
		return ("FRACTOLL - Julia by yabenman");
}

void	ft_init(t_fractol *fractol, int number)
{
	fractol->cnx = mlx_init();
	fractol->window = mlx_new_window(fractol->cnx, WIDTH, HEIGHT, ft_get_title(fractol));
	fractol->max_it = 100;
	fractol->ox = 0;
	fractol->oy = 0;
	fractol->zoom = 2;
	fractol->image.img_ptr = mlx_new_image(fractol->cnx, WIDTH, HEIGHT);
	fractol->image.pixels_ptr = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bits_per_pixel, &fractol->image.line_len,
			&fractol->image.endian);
	fractol->color = 0xff801;
	fractol->color_code = 0;
	fractol->julia = (fractol == 2);
	fractol->julia_move = 0;
	fractol->var.a_r = -0.466;
	fractol->var.b_r = 0.622;
}

int main(int ac, char **av){
    t_fractol fractol;
    int number;

    if (ac == 2)
    {
        number = ft_atoi(av[1]);
        if(number == 1 || number == 2)
        {
            ft_instructions();
            ft_init(&fractol, number);
        }
        else
           write(1, "Usage:\t./fractol [1, 2]\n", 28);
	       write(1, "[1]:\tMandelbrot\n[2]:\tJulia\n", 47);
        
    }
    
}