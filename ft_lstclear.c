/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:26:47 by eberger           #+#    #+#             */
/*   Updated: 2023/01/27 15:13:00 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstdel;

	while (*lst)
	{
		del((*lst)->content);
		lstdel = *lst;
		*lst = lstdel->next;
		free(lstdel);
	}
}
