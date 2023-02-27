/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:58:43 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 10:47:45 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first(t_list **l1, int *first, int size)
{
	int		i;
	t_list	*list1;

	i = 1;
	list1 = *l1;
	if (!first)
		return (0);
	while (i <= size)
	{
		if (first == (int *)list1->content)
			return (i);
		i++;
		list1 = list1->next;
	}
	return (0);
}

int	push_elem(t_list **dest, t_list **src, int size, char *str)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(dest, src, str);
		i++;
	}
	return (0);
}

int	test_d(int size)
{
	int	i;

	i = 1;
	while (size / 2 > 1)
	{
		i++;
		size /= 2;
	}
	return (i);
}

int	weight_list(t_list **l1, int sizelist)
{
	t_list	*elem_min;
	t_list	*list;
	int		i;

	i = 0;
	while (i < sizelist)
	{
		list = *l1;
		while (list->weight != -1)
			list = list->next;
		elem_min = list;
		while (list->next)
		{
			if (*(int *)elem_min->content > *(int *)list->next->content
				&& list->next->weight == -1)
				elem_min = list->next;
			list = list->next;
		}
		elem_min->weight = i;
		i++;
	}
	return (1);
}

int	sort(t_list **l1, t_list **l2)
{
	int	sizelist;

	sizelist = ft_lstsize(*l1);
	weight_list(l1, sizelist);
	if (sizelist == 2)
		sort_2(l1, NULL);
	else if (sizelist <= 3)
		sort_3(l1);
	else if (sizelist <= 15)
		insert_sort(l1, l2, sizelist);
	else if (sizelist < 200)
		quick_sort(l1, l2, sizelist);
	else
		quick_merge_sort(l1, l2, sizelist);
	return (1);
}
