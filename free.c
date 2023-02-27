/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:59:23 by eberger           #+#    #+#             */
/*   Updated: 2023/02/01 11:37:39 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_split(char **tab, int test)
{
	int	i;

	i = 0;
	if (test)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (1);
}

int	free_list(t_list **lst, int **tab_int)
{
	t_list	*ptr;

	if (*lst == NULL)
		return (0);
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	free(*tab_int);
	return (1);
}
