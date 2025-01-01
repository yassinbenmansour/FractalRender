/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:47:18 by yabenman          #+#    #+#             */
/*   Updated: 2025/01/01 03:42:48 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_atoi(char *num)
{
	int	nbr;
	int	index;

	index = -1;
	nbr = 0;
	while (num[++index])
		nbr = nbr * 10 + (num[index] - '0');
	return (nbr);
}

double	ft_map(int in, double min, double max)
{
	double	maped;

	maped = in * ((max - min) / 600) + min;
	return (maped);
}

int	ft_close(t_fractol *fractol)
{
	mlx_destroy_window(fractol->cnx, fractol->window);
	exit(0);
}

void	ft_instructions(void)
{
	write(1, "############## INSTRUCTION ##############\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "#               Zoom                    #\n", 43);
	write(1, "# mouse buttons - Use them whith julia  #\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "# r - Reset                             #\n", 43);
	write(1, "# c - Change Color                      #\n", 43);
	write(1, "# p - Change fractal                    #\n", 43);
	write(1, "# z - Increase the max iteration        #\n", 43);
	write(1, "# n - Decrease the max iteration        #\n", 43);
	write(1, "# esc | q - Quit                        #\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "#                                       #\n", 43);
	write(1, "############## INSTRUCTION ##############\n", 43);
}

double	ft_atof(char *str, double res)
{
	int	i;
	int	sign;
	int	divider;

	i = -1;
	res = 0;
	sign = 1;
	divider = 1;
	if (str[++i] == '-')
		sign = -1;
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i++] == '.')
	{
		while (str[i])
		{
			res = res * 10 + str[i++] - '0';
			divider *= 10;
		}
	}
	return (res * sign / divider);
}
