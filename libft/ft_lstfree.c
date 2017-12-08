/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:44:47 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/06 11:50:35 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	while ((*lst))
	{
		free((*lst)->content);
		(*lst)->content_size = 0;
		(*lst) = (*lst)->next;
	}
	(*lst) = NULL;
}
