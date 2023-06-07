/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:55:08 by eberger           #+#    #+#             */
/*   Updated: 2023/06/07 10:07:59 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sort(t_list *list)
{
	t_list	*test_list;
	t_list	*next;	

	test_list = list;
	while (test_list)
	{
		next = test_list->next;
		if (next && *(int *)next->content < *(int *)test_list->content)
			return (1);
		test_list = next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**tab;
	int		test;
	int		*tab_int;
	t_list	*list[2];

	test = 0;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		test = 1;
	}
	else
		tab = argv + 1;
	if (!ft_test_error(argc, tab))
		return (0);
	list[0] = ft_list(tab, &tab_int);
	if (!check_double(&tab_int, ft_tablen(tab)))
		return (0);
	list[1] = NULL;
	free_split(tab, test);
	if (not_sort(list[0]))
		sort(&list[0], &list[1]);
	free_list(&list[0], &tab_int);
	return (1);
}
