/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:28:40 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 09:28:46 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_list **l)
{
	t_list	*last;
	t_list	*elem;

	last = ft_lstlast(*l);
	elem = *l;
	if (elem != last)
	{
		while (elem->next != last)
			elem = elem->next;
		elem->next = NULL;
		ft_lstadd_front(l, last);
	}
	return (1);
}

int	reverse_rotate_list(t_list **l, char *str)
{
	reverse_rotate(l);
	ft_putendl_fd(str, 1);
	return (1);
}

int	reverse_rotate_lists(t_list **l1, t_list **l2)
{
	reverse_rotate(l1);
	reverse_rotate(l2);
	ft_putendl_fd("rrr", 1);
	return (1);
}
