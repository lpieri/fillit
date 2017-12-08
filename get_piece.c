/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:54:41 by yfoucade          #+#    #+#             */
/*   Updated: 2017/12/08 14:15:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static void		find_coord(char *buf, int *coord)
{
	int	i;
	int	row;
	int col;

	i = 0;
	row = 0;
	col = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
		{
			row = i / 5;
			col = i % 5;
			if (row < coord[0])
				coord[0] = row;
			if (row > coord[1])
				coord[1] = row;
			if (col < coord[2])
				coord[2] = col;
			if (col > coord[3])
				coord[3] = col;
		}
		i++;
	}
	return ;
}

static int		*create_coord(void)
{
	int	*res;

	if (!(res = (int*)malloc(sizeof(int) * 4)))
		return (0);
	res[0] = 3;
	res[1] = 0;
	res[2] = 3;
	res[3] = 0;
	return (res);
}

static int		fill_new(char *buf, int *coord, t_tetris *new)
{
	int	i;
	int j;
	int	idb;
	int	jdb;

	i = -1;
	idb = 0;
	jdb = 0;
	if (!(new->tab = (char**)malloc(sizeof(char*) * new->nrow)))
		return (0);
	while (i < new->nrow)
	{
		if (!(new->tab[i] = (char*)malloc(sizeof(char) * new->ncol)))
			return (0);
		j = 0;
		while (j < new->ncol)
		{
			idb = i + coord[0];
			jdb = j + coord[2];
			new->tab[i][j++] = buf[5 * idb + jdb] == '#' ? 'A' + new->id : '.';
		}
		i++;
	}
	return (1);
}

int				add_tetris(t_tetris **matrix, char *buf, int id)
{
	t_tetris	*new;
	int			*coord;

	if (!((coord = create_coord())))
		return (0);
	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (0);
	new->id = id;
	find_coord(buf, coord);
	new->ncol = coord[3] - coord[2] + 1;
	new->nrow = coord[1] - coord[0] + 1;
	fill_new(buf, coord, new);
	matrix[id] = new;
	matrix[id + 1] = NULL;
	free(coord);
	return (1);
}
