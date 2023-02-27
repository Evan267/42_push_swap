/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:59:05 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 10:48:45 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}

int	ft_test_error(int argc, char **tab)
{
	int	i;
	int	j;

	if (argc == 1)
		return (ft_error("Error"));
	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (ft_error("Error"));
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_double(int **nb, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		tmp = (*nb)[i];
		j = i + 1;
		while (j < len)
		{
			if (tmp == (*nb)[j])
				return (ft_error("Error"));
			j++;
		}
		i++;
	}
	return (1);
}
