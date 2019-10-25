/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizetile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:05 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 00:01:51 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static void		sizetilebis(t_env *env)
{
	if (env->mx <= 10 && env->my <= 10)
	{
		env->tx = 7;
		env->ty = 7;
		env->margex = 140;
	}
	else if (env->mx <= 13 && env->my <= 13)
	{
		env->tx = 6;
		env->ty = 6;
		env->margex = 130;
	}
	else if (env->mx <= 23 && env->my <= 23)
	{
		env->tx = 5;
		env->ty = 5;
		env->margex = 120;
	}
	else
	{
		env->tx = 3;
		env->ty = 3;
		env->margex = 233;
	}
}

void			sizetile(t_env *env)
{
	env->margey = 0;
	env->zbonus = 1;
	env->color = 0x0FFFFFF;
	if (env->mx <= 60 && env->my <= 60)
		sizetilebis(env);
	else
	{
		env->tx = 2;
		env->ty = 2;
		env->margex = 250;
	}
}
