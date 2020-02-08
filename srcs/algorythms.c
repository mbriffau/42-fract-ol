/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:22:27 by nben-haj          #+#    #+#             */
/*   Updated: 2017/10/05 00:35:10 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	basic_init(t_env *e)
{
	e->x1 = -1.1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -(WIDTH / 2) + (WIDTH / 6);
	e->imy = -(HEIGHT / 2) + (HEIGHT / 6);
	basic(e);
}

void	basic(t_env *e)
{
	int		x;
	int		y;
	int		i;
	int		(*f)(t_env *e);

	f = (e->fmap & MANDELBROT ? &mandelbrot_run : &burn_run);
	i = 0;
	x = e->imx - 1;
	while (++i < WIDTH)
	{
		++x;
		y = e->imy - 1;
		while (++y < HEIGHT + e->imy)
		{
			e->cr = x / e->zoom + e->x1;
			e->ci = y / e->zoom + e->y1;
			e->zr = 0;
			e->zi = 0;
			color(f(&*e), &*e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		mandelbrot_run(t_env *e)
{
	int			i;

	i = -1;
	while ((++i < e->imax) && ((e->zr * e->zr + e->zi * e->zi) < 4))
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * e->zi * e->tmp + e->ci;
	}
	return (i);
}

int		burn_run(t_env *e)
{
	int			i;

	i = -1;
	while ((++i < e->imax) && ((e->zr * e->zr + e->zi * e->zi) < 4))
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * fabsl(e->zi * e->tmp) + e->ci;
	}
	return (i);
}
