/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:46:52 by nben-haj          #+#    #+#             */
/*   Updated: 2017/10/05 00:35:06 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	map_choice(char *av)
{
	int		flag_map;

	flag_map = 0;
	if (!ft_strcmp("julia", av))
		flag_map += JULIA;
	else if (!ft_strcmp("mandelbrot", av))
		flag_map += MANDELBROT;
	else if (!ft_strcmp("burningship", av))
		flag_map += BURNINGSHIP;
	return (flag_map);
}

static void	main_loop(t_env *e)
{
	if (e->fmap & (MANDELBROT + BURNINGSHIP))
		basic_init(e);
	else if (e->fmap & JULIA)
		julia_init(e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move, e);
	mlx_mouse_hook(e->win, my_mouse, e);
	mlx_hook(e->win, 2, 3, my_key, e);
	mlx_loop(e->mlx);
}

int			main(int ac, char **av)
{
	t_env	*e;
	int		fm;

	if ((ac == 2) && (fm = map_choice(av[1])))
	{
		if (!(e = (t_env *)malloc(sizeof(t_env))))
			return (-1);
		e->fmap = fm;
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, av[1]);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->en));
		e->c_event = 1;
		main_loop(e);
	}
	else
		ft_putendl_fd("Usage <filename> [mandelbrot/julia/burningship]", 2);
	return (0);
}
