/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 8517/05/85 85:01:43 by nben-haj          #+#    #+#             */
/*   Updated: 2017/10/05 00:36:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 1)
	{
		e->imx += x / 5;
		e->imy += y / 5;
		e->zoom *= 1.2;
		e->imx *= 1.2;
		e->imy *= 1.2;
	}
	else if (keycode == 4 || keycode == 2)
	{
		e->imx -= x / 5;
		e->imy -= y / 5;
		e->zoom /= 1.2;
		e->imx /= 1.2;
		e->imy /= 1.2;
	}
	mlx_clear_window(e->mlx, e->win);
	if (e->fmap & (MANDELBROT + BURNINGSHIP))
		basic(e);
	else if (e->fmap & JULIA)
		julia(e);
}

static void	event_color(int kc, t_env *e)
{
	e->c_event = ((kc == 83) ? 1 : e->c_event);
	e->c_event = ((kc == 84) ? 2 : e->c_event);
	e->c_event = ((kc == 85) ? 4 : e->c_event);
	e->c_event = ((kc == 86) ? 8 : e->c_event);
	e->c_event = ((kc == 87) ? 16 : e->c_event);
	e->c_event = ((kc == 82) ? 0 : e->c_event);
	if ((kc >= 91 && kc <= 92) || kc == 88)
	{
		kc == 91 ? e->c_mod -= 1 : 0;
		kc == 92 ? e->c_mod += 1 : 0;
		kc == 88 ? e->c_mod = 0 : 0;
	}
}

int			my_key(int kc, t_env *e)
{
	if (kc == KEY_P)
		e->stop = (e->stop ? 0 : 1);
	else if (kc == KEY_ESCAPE)
	{
		free(e);
		exit(EXIT_SUCCESS);
	}
	else if ((kc >= 82 && kc <= 88) || (kc >= 91 && kc <= 92))
	{
		event_color(kc, &*e);
		mlx_clear_window(e->mlx, e->win);
		clen_next(kc, e);
	}
	else if (kc == KEY_PAD_ADD || kc == KEY_PAD_SUB || kc == KEY_S
	|| kc == KEY_A || kc == KEY_D || kc == KEY_W || kc == KEY_R)
		clean_event(kc, e);
	return (0);
}

void		clean_event(int keyboard, t_env *e)
{
	if (keyboard == 69 || keyboard == 78)
	{
		if (keyboard == 69)
			e->imax += 50;
		else if (keyboard == 78)
			e->imax > 0 ? e->imax -= 50 : 0;
		ft_putstr("Iteration max = ");
		ft_putnbr(e->imax);
		ft_putchar('\n');
	}
	keyboard == KEY_D ? e->imx -= 5 : 0;
	keyboard == KEY_A ? e->imx += 5 : 0;
	keyboard == KEY_S ? e->imy -= 5 : 0;
	keyboard == KEY_W ? e->imy += 5 : 0;
	mlx_clear_window(e->mlx, e->win);
	clen_next(keyboard, e);
}

void		clen_next(int keyboard, t_env *e)
{
	if (keyboard == KEY_R)
		e->fmap & JULIA ? julia_init(e) : basic_init(e);
	else
		e->fmap & JULIA ? julia(e) : basic(e);
}
