/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:07:26 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/08 14:07:22 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef	struct		s_tetris
{
	char			**tab;
	int				id;
	int				nrow;
	int				ncol;
}					t_tetris;

t_tetris			**read_file(int fd);
int					add_tetris(t_tetris **matrix, char *buf, int id);
char				**backtracking1(t_tetris **matrix);
int					clean(char *buf, t_tetris **matrix, int ret);
int					ft_sqrt_up(t_tetris **matrix);
void				clean_matrix(t_tetris **matrix);

#endif
