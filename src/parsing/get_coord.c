/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:17 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 22:26:20 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "env.h"

static void	format(int c)
{
	if (c)
	{
		ft_putendl("Invalid Format");
		exit(0);
	}
}

void		get_coord(t_env *env, char **file)
{
	char	*buffer;
	int		fd;
	char	**ret;
	char	**cleaner;

	env->my = 0;
	env->mair = 0;
	fd = open(*file, O_RDWR);
	format(fd <= 0);
	while ((get_next_line(fd, &buffer)) != 0)
	{
		ret = ft_strsplit(buffer, ' ');
		cleaner = ret;
		free(buffer);
		while (*ret)
		{
			env->mair++;
			free(*ret++);
		}
		env->my++;
		free(cleaner);
	}
	format(env->my == 0);
	env->mx = env->mair / env->my;
	format((env->mx * env->my) != env->mair);
}
