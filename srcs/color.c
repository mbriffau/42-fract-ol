/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 01:02:27 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/05 00:35:12 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(int i, t_env *e, int x, int y)
{
	int r;
	int g;
	int b;

	if (i == e->imax)
		e->c = BLACK;
	else
	{
		r = ((i * 5) * 2) + e->c_mod;
		g = ((255 - (i * 10)) * 2) + e->c_mod;
		b = ((255 - (i * 2)) * 2) + e->c_mod;
		e->c = (!e->c_event ? (r << 16) + (g << 8) + b : e->c);
		e->c = (e->c_event & 1 ? (r << 16) + (b << 8) + g : e->c);
		e->c = (e->c_event & 2 ? (b << 16) + (r << 8) + g : e->c);
		e->c = (e->c_event & 4 ? (b << 16) + (g << 8) + r : e->c);
		e->c = (e->c_event & 8 ? (g << 16) + (b << 8) + r : e->c);
		e->c = (e->c_event & 16 ? (g << 16) + (r << 8) + b : e->c);
	}
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4 + 1] = e->c >> 8;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4 + 2] = e->c >> 16;
}
