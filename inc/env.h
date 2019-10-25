/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:43:26 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/04 17:53:38 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WIN_WIDTH	2300
# define WIN_WEIGHT	1300

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				mx;
	int				my;
	int				mair;
	int				*tz;
	int				tx;
	int				ty;
	int				margex;
	int				margey;
	int				za;
	int				zb;
	int				zbonus;
	int				color;
}					t_env;

void				get_coord(t_env *env, char **file);
void				get_map(t_env *env, char **file);
void				*create_window(t_env *coord);
void				sizetile(t_env *env);
void				wireframe_iso(t_env *coord);
void				draw_event(t_env *env);
t_env				*zoom(t_env *env, int keycode);
t_env				*heightz(t_env *env, int keycode);
t_env				*trips(t_env *env, int keycode);
t_env				*rgb(t_env *env, int keycode);

#endif
