/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:11 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 16:15:08 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "env.h"

static int		e_keyboard(int keycode, t_env *env)
{
	if (keycode == 53 || keycode == 12)
	{
		ft_putendl("Exit Program");
		exit(0);
	}
	else if (keycode == 69 || keycode == 78)
		env = zoom(env, keycode);
	else if (keycode >= 123 && keycode <= 126)
		env = trips(env, keycode);
	else if (keycode == 35 || keycode == 46)
		heightz(env, keycode);
	else if (keycode == 15 || keycode == 5 || keycode == 11)
		rgb(env, keycode);
	return (0);
}

void			*create_window(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_WEIGHT, "Wireframe");
	wireframe_iso(env);
	mlx_key_hook(env->win, e_keyboard, env);
	mlx_loop(env->mlx);
	return (0);
}
