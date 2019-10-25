/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:21 by lmunoz-q          #+#    #+#             */
/*   Updated: 2017/12/02 22:26:34 by lmunoz-q         ###   ########.fr       */
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

void		get_map(t_env *env, char **file)
{
	int		i;
	char	*buffer;
	int		fd;
	char	**ret;
	char	**cleaner;

	i = 0;
	env->tz = (int *)ft_memalloc(sizeof(int) * env->mair);
	fd = open(*file, O_RDWR);
	format(fd <= 0);
	while ((get_next_line(fd, &buffer)) != 0)
	{
		ret = ft_strsplit(buffer, ' ');
		cleaner = ret;
		free(buffer);
		while (*ret)
		{
			format(ft_strlen(*ret) >= 5);
			env->tz[i++] = ft_atoi(*ret);
			free(*ret++);
		}
		free(cleaner);
	}
}
