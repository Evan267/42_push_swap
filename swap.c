/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:16:59 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 09:17:02 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list **l)
{
	t_list	*ptr_swap;

	if (*l && (*l)->next)
	{
		ptr_swap = *l;
		*l = (*l)->next;
		ptr_swap->next = (*l)->next;
		(*l)->next = ptr_swap;
		return (1);
	}
	return (0);
}

int	swap_list(t_list **l, char *str)
{
	swap(l);
	ft_putendl_fd(str, 1);
	return (1);
}

int	swap_lists(t_list **l1, t_list **l2)
{
	swap(l1);
	swap(l2);
	ft_putendl_fd("ss", 1);
	return (1);
}
