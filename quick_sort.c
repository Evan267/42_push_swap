/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:28:03 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 11:04:32 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_by_pivot(t_list **l1, t_list **l2, int pivot, int sizelist)
{
	int	i;

	i = 0;
	while (i < sizelist)
	{
		if ((*l1)->weight < pivot)
		{
			push(l2, l1, "pb");
			if (ft_lstsize(*l2) > 1 && (*l2)->weight < (pivot / 2))
				rotate_list(l2, "rb");
		}
		else
			rotate_list(l1, "ra");
		i++;
	}
	return (1);
}

int	sort_second_part(t_list **l1, t_list **l2, int pivot, int sizelist)
{
	int	i;
	int	r_pivot;

	i = 0;
	r_pivot = find_last_j(sizelist - pivot);
	while (i < sizelist - pivot)
	{
		if ((*l1)->weight < pivot + r_pivot)
			push(l2, l1, "pb");
		else
			rotate_list(l1, "ra");
		i++;
	}
	return (pivot + r_pivot);
}

int	find_next(t_list **l, int weight)
{
	int		i;
	t_list	*list;

	list = *l;
	i = 0;
	while (list->weight != weight)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	push_and_sort(t_list **l1, t_list **l2, int pivot)
{
	int	i;
	int	next;
	int	sizel2;

	i = 0;
	sizel2 = ft_lstsize(*l2);
	while (i < sizel2)
	{
		next = find_next(l2, pivot - ++i);
		if (next < ft_lstsize(*l2) / 2)
		{
			while (0 < next--)
				rotate_list(l2, "rb");
		}
		else
		{
			while (ft_lstsize(*l2) - next > 0)
			{
				reverse_rotate_list(l2, "rrb");
				next++;
			}
		}
		push(l1, l2, "pa");
	}
	return (pivot - i);
}

int	quick_sort(t_list **l1, t_list **l2, int sizelist)
{
	int	pivot;
	int	r_pivot;

	pivot = find_last_j(sizelist);
	push_by_pivot(l1, l2, pivot, sizelist);
	r_pivot = pivot;
	while (ft_lstsize(*l1) > 2)
		r_pivot = sort_second_part(l1, l2, r_pivot, sizelist);
	sort_2(l1, NULL);
	r_pivot = push_and_sort(l1, l2, r_pivot);
	return (0);
}
