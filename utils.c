/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:57 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 12:00:29 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last_j(int size)
{
	int	i;

	i = 1;
	while (i * 2 < size)
		i *= 2;
	return (i);
}

int	*ft_find_min(t_list **l1, int j)
{
	int		i;
	int		*tmp;
	t_list	*list1;

	i = 2;
	list1 = *l1;
	if (*(int *)list1->content < *(int *)list1->next->content)
		tmp = (int *)list1->content;
	else
		tmp = (int *)list1->next->content;
	list1 = list1->next;
	while (i < j)
	{
		list1 = list1->next;
		if (*tmp > *(int *)list1->content)
			tmp = (int *)list1->content;
		i++;
	}
	return (tmp);
}

int	ft_test_first_clean(t_list **l1, int j)
{
	int		i;
	int		k;
	t_list	*list1;

	i = 1;
	while (i < j)
	{
		list1 = (*l1)->next;
		k = i;
		while (*(int *)(*l1)->content < *(int *)list1->content && j > k++)
			list1 = list1->next;
		if (k == j)
		{
			rotate_list(l1, "ra");
			i++;
			if (i == k)
			{
				rotate_list(l1, "ra");
				i++;
			}
		}
		else
			break ;
	}
	return (i - 1);
}
