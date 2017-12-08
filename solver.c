/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:41:28 by yfoucade          #+#    #+#             */
/*   Updated: 2017/12/08 14:07:57 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static char		**create_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_memset(map[i], '.', sizeof(char) * size);
		map[i][size] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int		add_to_map(t_tetris *piece, char **map, int r_map, int c_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->nrow)
	{
		j = 0;
		while (j < piece->ncol)
		{
			if (map[i + r_map][j + c_map] != '.' && piece->tab[i][j] != '.')
				return (0);
			if (piece->tab[i][j] != '.')
				map[i + r_map][j + c_map] = piece->tab[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

static void		remove_tetris(char c, char **map)
{
	char *str;

	while (*map)
	{
		str = *map;
		while (*str)
		{
			if (*str == c)
				*str = '.';
			str++;
		}
		map++;
	}
}

static int		backtracking2(char **map, int size, t_tetris **matrix, int i)
{
	int	r;
	int c;

	if (matrix[i] == NULL)
		return (1);
	r = 0;
	while (r <= size - matrix[i]->nrow)
	{
		c = 0;
		while (c <= size - matrix[i]->ncol)
		{
			if (!(add_to_map(matrix[i], map, r, c)))
			{
				remove_tetris('A' + matrix[i]->id, map);
				c++;
				continue;
			}
			else if (backtracking2(map, size, matrix, i + 1))
				return (1);
			remove_tetris('A' + matrix[i]->id, map);
			c++;
		}
		r++;
	}
	return (0);
}

char			**backtracking1(t_tetris **matrix)
{
	int		n;
	char	**map;

	n = ft_sqrt_up(matrix);
	map = create_map(n);
	while (!(backtracking2(map, n, matrix, 0)) && n < 10)
	{
		free(map);
		n++;
		map = create_map(n);
	}
	clean_matrix(matrix);
	return (map);
}
