/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:54 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/01 18:15:42 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		ft_putendl("Invalid arguments");
	else
	{
		get_coord(&env, &argv[1]);
		get_map(&env, &argv[1]);
		sizetile(&env);
		create_window(&env);
	}
	return (0);
}
