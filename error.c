/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:59:05 by eberger           #+#    #+#             */
/*   Updated: 2023/06/22 09:12:21 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}

static void	ft_clear(char **tab, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

static int	ft_test_int(char *num)
{
	int	i;

	i = 0;
	while (num[i] == '-' || num[i] == '+')
		i++;
	if (ft_strlen(num + i) > 10
		|| ft_atoi(num) > 2147483647
		|| ft_atoi(num) < -2147483648)
		return (1);
	return (0);
}

int	ft_test_error(int argc, char **tab)
{
	int	i;
	int	j;

	if (argc == 1 || !tab[0])
		return (ft_error("Error"));
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_test_int(tab[i]))
			return (ft_clear(tab, argc), ft_error("Error"));
		while (tab[i][j])
		{
			if (j == 0 && !ft_isdigit(tab[i][j])
					&& tab[i][j] != '-' && tab[i][j] != '+')
				return (ft_clear(tab, argc), ft_error("Error"));
			else if ((j != 0 || (j == 0 && ft_strlen(tab[i]) == 1))
				&& !ft_isdigit(tab[i][j]))
				return (ft_clear(tab, argc), ft_error("Error"));
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
