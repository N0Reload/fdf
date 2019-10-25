/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:00 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/01/13 20:37:59 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "besenham.h"
#include "libft.h"

static t_coord		*isoh(t_coord *dst, t_coord *src, t_env *env)
{
	env->za = env->tz[src->xi + src->yi * env->mx];
	env->zb = env->tz[1 + src->xi + src->yi * env->mx];
	env->za *= env->zbonus;
	env->zb *= env->zbonus;
	dst->xa = (env->tx * src->xa) - (env->ty * src->ya);
	dst->xb = (env->tx * src->xb) - (env->ty * src->ya);
	dst->ya = (-env->za + (env->tx / 2) * src->xa) + ((env->ty / 2) * src->ya);
	dst->yb = (-env->zb + (env->tx / 2) * src->xb) + ((env->ty / 2) * src->ya);
	return (dst);
}

static t_coord		*isov(t_coord *dst, t_coord *src, t_env *env)
{
	env->za = env->tz[src->xi + src->yi * env->mx];
	env->zb = env->tz[src->xi + (src->yi + 1) * env->mx];
	env->za *= env->zbonus;
	env->zb *= env->zbonus;
	dst->xa = (env->tx * src->xa) - (env->ty * src->ya);
	dst->xb = (env->tx * src->xa) - (env->ty * src->yb);
	dst->ya = (-env->za + (env->tx / 2) * src->xa) + ((env->ty / 2) * src->ya);
	dst->yb = (-env->zb + (env->tx / 2) * src->xa) + ((env->ty / 2) * src->yb);
	return (dst);
}

static t_coord		*line(t_coord *coord)
{
	int w;
	int h;

	coord->dx1 = 0;
	coord->dy1 = 0;
	coord->dx2 = 0;
	coord->dy2 = 0;
	w = coord->xb - coord->xa;
	h = coord->yb - coord->ya;
	if (w != 0)
		coord->dx1 = w < 0 ? -1 : 1;
	if (h != 0)
		coord->dy1 = h < 0 ? -1 : 1;
	coord->dx2 = coord->dx1;
	coord->longest = ABS(w);
	coord->shortest = ABS(h);
	if (!(coord->longest > coord->shortest))
	{
		coord->longest = ABS(h);
		coord->shortest = ABS(w);
		if (h != 0)
			coord->dy2 = h < 0 ? -1 : 1;
		coord->dx2 = 0;
	}
	return (coord);
}

static void			draw_line(t_coord *coord, t_env *env)
{
	int x;
	int y;
	int i;
	int numerator;

	i = 0;
	x = coord->xa;
	y = coord->ya;
	numerator = coord->longest >> 1;
	while (i++ <= coord->longest)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, env->color);
		numerator += coord->shortest;
		if (!(numerator < coord->longest))
		{
			numerator -= coord->longest;
			x += coord->dx1;
			y += coord->dy1;
		}
		else
		{
			x += coord->dx2;
			y += coord->dy2;
		}
	}
}

void				wireframe_iso(t_env *env)
{
	int				*z;
	t_coord			h;
	t_coord			v;
	t_coord			pos;

	pos.yi = -1;
	z = env->tz;
	while (++pos.yi < env->my && (pos.xi = -1))
		while (++pos.xi < env->mx)
		{
			pos.xa = pos.xi * env->tx + env->margex;
			pos.ya = pos.yi * env->ty + env->margey;
			pos.xb = (pos.xi + 1) * env->tx + env->margex;
			pos.yb = (pos.yi + 1) * env->ty + env->margey;
			if (pos.xi < env->mx - 1)
			{
				h = *isoh(&h, &pos, env);
				draw_line(line(&h), env);
			}
			if (pos.yi < env->my - 1)
			{
				v = *isov(&v, &pos, env);
				draw_line(line(&v), env);
			}
		}
}
