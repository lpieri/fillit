/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:57:36 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/08 14:41:39 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		**map;
	t_tetris	**matrix;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [source_file]");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	matrix = read_file(fd);
	map = backtracking1(matrix);
	while (*map)
	{
		ft_putendl(*map);
		map++;
	}
	while (*map)
		free(*map++);
	return (0);
}
