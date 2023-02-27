/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:25:44 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 09:25:47 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **dest, t_list **src, char *str)
{
	t_list	*ptr_push;

	if (*src)
	{
		ptr_push = *src;
		*src = (*src)->next;
		if (*dest)
			ft_lstadd_front(dest, ptr_push);
		else
		{
			ptr_push->next = NULL;
			*dest = ptr_push;
		}
	}
	ft_putendl_fd(str, 1);
	return (1);
}
