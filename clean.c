/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:05:18 by yfoucade          #+#    #+#             */
/*   Updated: 2017/12/08 14:17:47 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	clean_matrix(t_tetris **matrix)
{
	int		j;

	j = 0;
	while (matrix[j])
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
}

int		clean(char *buf, t_tetris **matrix, int ret)
{
	if (buf)
		free(buf);
	if (!(ret))
	{
		free(matrix);
	}
	return (ret);
}
