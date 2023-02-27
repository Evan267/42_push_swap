/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:55:08 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 10:14:00 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**tab;
	int		test;
	int		*tab_int;
	t_list	*l1;
	t_list	*l2;

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
	l1 = ft_list(tab, &tab_int);
	if (!check_double(&tab_int, ft_tablen(tab)))
		return (0);
	l2 = NULL;
	free_split(tab, test);
	sort(&l1, &l2);
	free_list(&l1, &tab_int);
	return (1);
}
