/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trips.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:21:22 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 15:21:23 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*trips(t_env *env, int keycode)
{
	if (keycode == 123 || keycode == 124)
		env->margex += (keycode == 123 ? -10 : 10);
	else if (keycode == 125 || keycode == 126)
		env->margey += (keycode == 125 ? 10 : -10);
	draw_event(env);
	return (env);
}
