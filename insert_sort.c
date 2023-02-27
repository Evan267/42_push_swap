/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:59:54 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 09:20:44 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_last_is_first(t_list **l1)
{
	t_list	*last;
	t_list	*test;

	last = ft_lstlast(*l1);
	test = *l1;
	while (test && *(int *)test->content > *(int *)last->content)
		test = test->next;
	if (test && *(int *)test->content != *(int *)last->content)
		return (0);
	else
		return (1);
}

void	insert_sort_cond(t_list **l1, t_list **l2, int *tab, t_list **list1)
{
	if (*(int *)(*list1)->content > *(int *)(*list1)->next->content)
	{
		while (tab[0] > 0)
		{
			push(l2, l1, "pb");
			tab[1]++;
			tab[0]--;
		}
		if (*(int *)(*l1)->content > *(int *)ft_lstlast(*list1)->content)
			rotate_list(l1, "ra");
		if (*(int *)(*l1)->content > *(int *)(*l1)->next->content)
			swap_list(l1, "sa");
		*list1 = *l1;
	}
	if (tab[1] && *l2 && *(int *)(*list1)->content < *(int *)(*l2)->content)
	{
		push(l1, l2, "pa");
		tab[1]--;
		*list1 = *l1;
	}
	else
	{
		tab[0]++;
		*list1 = (*list1)->next;
	}
}

int	insert_sort(t_list **l1, t_list **l2, int size)
{
	t_list	*list1;
	int		tab[2];

	tab[0] = 0;
	tab[1] = 0;
	if (ft_last_is_first(l1))
		reverse_rotate_list(l1, "rra");
	list1 = *l1;
	while (list1->next && tab[0] + tab[1] < size)
	{
		if (*(int *)list1->content > *(int *)ft_lstlast(list1)->content
			&& !tab[0])
		{
			rotate_list(l1, "ra");
			list1 = *l1;
		}
		else
			insert_sort_cond(l1, l2, tab, &list1);
	}
	while (*l2 && tab[1])
	{
		push(l1, l2, "pa");
		tab[1]--;
	}
	return (1);
}
