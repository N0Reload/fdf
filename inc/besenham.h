/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   besenham.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:43:21 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/11/27 17:43:22 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BESENHAM_H
# define BESENHAM_H

typedef struct		s_coord
{
	int				xa;
	int				xb;
	int				ya;
	int				yb;
	int				xi;
	int				yi;
	int				dx1;
	int				dy1;
	int				dx2;
	int				dy2;
	int				longest;
	int				shortest;
}					t_coord;

#endif
