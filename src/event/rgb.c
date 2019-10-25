/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:10:36 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 16:14:43 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*rgb(t_env *env, int keycode)
{
	if (keycode == 15)
		env->color = 0x0FF0000;
	else if (keycode == 5)
		env->color = 0x000FF00;
	if (keycode == 11)
		env->color = 0x00000FF;
	wireframe_iso(env);
	return (env);
}
