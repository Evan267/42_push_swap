/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:33:38 by eberger           #+#    #+#             */
/*   Updated: 2023/01/11 15:25:00 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = 0;
	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->weight = -1;
		tmp->next = 0;
	}
	return (tmp);
}
