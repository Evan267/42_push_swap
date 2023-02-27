/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:00:33 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 14:32:45 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fusion(t_list **l1, t_list **l2, int size)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = ft_lstsize(*l2);
	while (*l2 && i[0] < size)
	{
		i[2] = ft_lstsize(*l2);
		if (i[2] > 1 && !(i[1]++))
			reverse_rotate_list(l2, "rrb");
		if (*(int *)(*l1)->content > *(int *)(*l2)->content
				|| i[0] + i[2] == size)
		{
			i[1] = 0;
			push(l1, l2, "pa");
			rotate_list(l1, "ra");
		}
		else if (*(int *)(*l1)->content < *(int *)(*l2)->content)
			rotate_list(l1, "ra");
		i[0]++;
	}
	while (size > i[0]++)
		rotate_list(l1, "ra");
	return (0);
}

int	rest_sort(t_list **l1, t_list **l2, int sizelist, int *d)
{
	int	i[3];

	i[0] = 1;
	push_elem(l2, l1, d[0], "pb");
	if (d[0] == 3)
		sort_3_list2(l2);
	if (d[0] == 2 & d[1] <= 4)
		sort_2(l1, l2);
	if (d[1] * 2 < sizelist)
	{
		i[1] = *(int *)ft_lstlast(*l1)->content;
		if (*l2)
			i[2] = *(int *)ft_lstlast(*l2)->content;
		while (i[0] <= d[1] && i[2] < i[1])
		{
			reverse_rotate_list(l1, "rra");
			i[1] = *(int *)ft_lstlast(*l1)->content;
			i[0]++;
		}
		i[0]--;
	}
	else
		i[0] = d[1];
	fusion(l1, l2, d[0] + i[0]);
	return (1);
}

void	merge(t_list **l1, t_list **l2, int *d, int *first)
{
	while (!d[0])
	{
		if (!first)
			first = ft_find_min(l1, d[1]);
		d[2] = ft_test_first_clean(l1, d[1]);
		if (d[1] - d[2] == 2)
			sort_2(l1, l2);
		else
		{
			push_elem(l2, l1, (d[1] / 2) - d[2], "pb");
			if (d[1] <= 4)
				sort_2(l1, l2);
		}
		fusion(l1, l2, d[1] - d[2]);
		d[0] = ft_first(l1, first, d[1]);
	}
}

void	merge_sort(t_list **l1, t_list **l2, int sizelist)
{
	int	*first;
	int	d[3];

	d[1] = 4;
	while (d[1] * 2 <= sizelist)
	{
		first = NULL;
		d[0] = ft_first(l1, first, d[1]);
		d[2] = 0;
		merge(l1, l2, d, first);
		d[0] -= 1;
		if (d[0])
			rest_sort(l1, l2, sizelist, d);
		d[1] *= 2;
	}
}

int	quick_merge_sort(t_list **l1, t_list **l2, int sizelist)
{
	int	pivot;

	pivot = find_last_j(sizelist);
	push_by_pivot(l1, l2, pivot, sizelist);
	push_elem(l1, l2, pivot, "pa");
	merge_sort(l1, l2, sizelist);
	return (0);
}
