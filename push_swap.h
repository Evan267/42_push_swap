/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:26:06 by eberger           #+#    #+#             */
/*   Updated: 2023/02/02 12:10:11 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				weight;
	struct s_list	*next;
}	t_list;

int		ft_error(char *str);
int		ft_test_error(int argc, char **tab);
int		check_double(int **tab, int len);
int		free_split(char **tab, int test);
int		free_list(t_list **lst, int **tab_int);

int		ft_tablen(char **tab);
t_list	*ft_list(char **tab, int **atoi);

int		find_last_j(int size);
int		*ft_find_min(t_list **l1, int j);
int		ft_test_first_clean(t_list **l1, int j);

void	print_list(t_list *l1, t_list *l2);//A SUPPRIMER
int		push_elem(t_list **dest, t_list **src, int size, char *str);
int		ft_first(t_list **l1, int *first, int size);
int		push_by_pivot(t_list **l1, t_list **l2, int pivot, int sizelist);

int		sort_2(t_list **l1, t_list **l2);
int		sort_3(t_list **list);
void	sort_3_list2(t_list **l2);
int		insert_sort(t_list **l1, t_list **l2, int size);
int		quick_merge_sort(t_list	**l1, t_list **l2, int sizelist);
int		quick_sort(t_list **l1, t_list **l2, int sizelist);
int		sort(t_list **l1, t_list **l2);

int		reverse_rotate_list(t_list **l, char *str);
int		reverse_rotate_lists(t_list **l1, t_list **l2);
int		rotate_list(t_list **l, char *str);
int		rotate_lists(t_list **l1, t_list **l2);
int		push(t_list **dest, t_list **src, char *str);
int		swap_list(t_list **l, char *str);
int		swap_lists(t_list **l1, t_list **l2);

int		ft_isdigit(int chr);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
