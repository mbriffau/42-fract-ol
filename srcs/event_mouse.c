/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 01:04:08 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/05 00:35:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		my_mouse(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 1 || keycode == 4 || keycode == 2)
	{
		zoom(keycode, x, y, e);
		return (0);
	}
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if ((x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		&& (e->fmap & JULIA) && e->stop == 0)
		return (0);
	if ((e->fmap & JULIA) && e->stop == 0)
	{
		e->paramx = x;
		e->paramy = y;
		mlx_clear_window(e->mlx, e->win);
		julia(e);
	}
	return (0);
}
