/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:29:15 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 10:52:53 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_lists(int *size, t_list **l1, t_list **l2)
{
	size[0] = 0;
	size[1] = 0;
	if (l2)
		size[1] = ft_lstsize(*l2);
	if (l1)
		size[0] = ft_lstsize(*l1);
}

int	sort_2(t_list **l1, t_list **l2)
{
	int	size[2];

	size_lists(size, l1, l2);
	if (size[1] > 1 && size[0] > 1)
	{
		if (*(int *)(*l1)->content > *(int *)(*l1)->next->content
				&& (int *)(*l2)->content && (int *)(*l2)->next->content
				&& *(int *)(*l2)->content < *(int *)(*l2)->next->content)
			swap_lists(l1, l2);
		else if (*(int *)(*l1)->content > *(int *)(*l1)->next->content)
			swap_list(l1, "sa");
		else if (*(int *)(*l2)->content < *(int *)(*l2)->next->content)
			swap_list(l2, "sb");
	}
	else if (size[0] > 1)
	{
		if (*(int *)(*l1)->content > *(int *)(*l1)->next->content)
			swap_list(l1, "sa");
	}
	else if (size[1] > 1)
	{
		if (*(int *)(*l2)->content < *(int *)(*l2)->next->content)
			swap_list(l2, "sb");
	}
	return (1);
}
