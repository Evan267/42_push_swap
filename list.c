/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:54:13 by eberger           #+#    #+#             */
/*   Updated: 2023/06/07 08:48:58 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_list	*ft_list(char **tab, int **atoi)
{
	t_list	*first;
	t_list	*new;
	int		tlen;
	int		i;

	i = 0;
	tlen = ft_tablen(tab);
	*atoi = malloc(sizeof(int *) * tlen);
	if (!*atoi)
		return (0);
	(*atoi)[i] = ft_atoi(tab[i]);
	first = ft_lstnew(*atoi + i);
	i++;
	while (tab[i])
	{
		(*atoi)[i] = ft_atoi(tab[i]);
		new = ft_lstnew(*atoi + i);
		ft_lstadd_back(&first, new);
		i++;
	}
	return (first);
}
