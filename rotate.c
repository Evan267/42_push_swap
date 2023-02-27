/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:29:00 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 09:29:04 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_list **l)
{
	t_list	*ptr_rotate;

	if (*l)
	{
		ptr_rotate = *l;
		*l = (*l)->next;
		ptr_rotate->next = NULL;
		ft_lstadd_back(l, ptr_rotate);
	}
	return (1);
}

int	rotate_list(t_list **l, char *str)
{
	rotate(l);
	ft_putendl_fd(str, 1);
	return (1);
}

int	rotate_lists(t_list **l1, t_list **l2)
{
	rotate(l1);
	rotate(l2);
	ft_putendl_fd("rr", 1);
	return (1);
}
