/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:29:31 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 12:09:04 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_list2(t_list **l2)
{
	if (*(int *)(*l2)->content < *(int *)(*l2)->next->next->content)
	{
		if (*(int *)(*l2)->content > *(int *)(*l2)->next->content)
			rotate_list(l2, "rb");
		rotate_list(l2, "rb");
	}
	if (*(int *)(*l2)->content < *(int *)(*l2)->next->content)
		swap_list(l2, "sb");
	if (*(int *)(*l2)->next->content < *(int *)(*l2)->next->next->content)
	{
		rotate_list(l2, "rb");
		swap_list(l2, "sb");
		reverse_rotate_list(l2, "rrb");
	}
}

int	sort_3(t_list **list)
{
	if (*(int *)(*list)->content > *(int *)(*list)->next->next->content)
	{
		if (*(int *)(*list)->content < *(int *)(*list)->next->content)
			rotate_list(list, "ra");
		rotate_list(list, "ra");
	}
	if (*(int *)(*list)->content > *(int *)(*list)->next->content)
		swap_list(list, "sa");
	if (*(int *)(*list)->next->content > *(int *)(*list)->next->next->content)
	{
		reverse_rotate_list(list, "rra");
		swap_list(list, "sa");
	}
	return (0);
}
