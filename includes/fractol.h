/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:47:27 by nben-haj          #+#    #+#             */
/*   Updated: 2017/10/05 00:41:04 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "colors.h"
# include "keycode.h"
# include <math.h>

# define HEIGHT				500
# define WIDTH				800

# define MOTION_NOTIFY		6
# define PTR_MOTION_MASK	(1L << 6)

# define MANDELBROT			(1 << 0)
# define JULIA				(1 << 1)
# define BURNINGSHIP		(1 << 2)

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			s_l;
	int			en;
	char		*str;
	int			fmap;
	int			imax;
	int			imx;
	int			imy;
	int			paramx;
	int			paramy;
	int			stop;
	int			c;
	int			c_event;
	int			c_mod;
	long double tmp;
	long double	x1;
	long double	y1;
	long double	zoom;
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
}				t_env;

int				my_key(int keyboard, t_env *e);
int				my_mouse(int keycode, int x, int y, t_env *e);
void			zoom(int keycode, int x, int y, t_env *e);
int				mouse_move(int x, int y, t_env *e);
void			julia_init(t_env *e);
void			julia(t_env *e);
void			julia_run(t_env *e, int x, int y);
void			basic_init(t_env *e);
void			basic(t_env *e);
int				burn_run(t_env *e);
int				mandelbrot_run(t_env *e);
void			color(int i, t_env *e, int x, int y);
void			clean_event(int keyboard, t_env *e);
void			clen_next(int keyboard, t_env *e);

#endif
