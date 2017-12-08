/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:18:00 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/08 16:24:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int		count_connections(char *buf)
{
	int	i;
	int	nb_connect;
	int	nb_blocks;

	i = 0;
	nb_blocks = 0;
	nb_connect = 0;
	while (i <= 19)
	{
		if (buf[i] == '#')
			++nb_blocks;
		if (buf[i] == '#' && (i - 5) >= 0 && buf[i - 5] == '#')
			++nb_connect;
		if (buf[i] == '#' && (i + 5) <= 18 && buf[i + 5] == '#')
			++nb_connect;
		if (buf[i] == '#' && i % 5 != 0 && buf[i - 1] == '#')
			++nb_connect;
		if (buf[i] == '#' && i % 5 != 3 && buf[i + 1] == '#')
			++nb_connect;
		i++;
	}
	if (!((nb_connect == 6 || nb_connect == 8) && nb_blocks == 4))
		return (0);
	return (1);
}

static int		check_buf(char *buf, int last)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (((i % 5) == 4 || (i == 20 && !(last))) && buf[i] != '\n')
			return (0);
		else if ((i % 5 != 4 && i != 20) && buf[i] != '.' && buf[i] != '#')
			return (0);
		i++;
	}
	if (!(count_connections(buf)))
		return (0);
	return (1);
}

static int		is_valid(int fd, t_tetris **matrix)
{
	char	*buf;
	int		ret;
	int		last;
	int		id;

	id = 0;
	last = 0;
	if (!(buf = (char*)malloc(sizeof(char) * 22)))
		return (clean(NULL, matrix, 0));
	buf[22] = 0;
	while ((ret = read(fd, buf, 21)))
	{
		if (ret == 20)
			last = 1;
		if (!(check_buf(buf, last)) || !(add_tetris(matrix, buf, id++)))
			return (clean(buf, matrix, 0));
	}
	if (!(last) || id > 26)
		return (clean(buf, matrix, 0));
	return (clean(buf, NULL, 1));
}

t_tetris		**read_file(int fd)
{
	t_tetris	**matrix;

	if (!(matrix = (t_tetris**)malloc(sizeof(t_tetris*) * 27)))
		return (0);
	if (!(is_valid(fd, matrix)))
	{
		ft_putendl("error");
		exit(1);
	}
	close(fd);
	return (matrix);
}
