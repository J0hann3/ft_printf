/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:27:15 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/17 10:52:54 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst_printf	*ft_lstnew_printf(char *content, size_t len)
{
	t_lst_printf	*new;

	new = malloc(sizeof(t_lst_printf));
	if (new == 0)
		return (0);
	new->next = NULL;
	new->content = content;
	new->len = len;
	return (new);
}

t_lst_printf	*ft_lstlast_printf(t_lst_printf *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_printf(t_lst_printf **lst, t_lst_printf *new)
{
	t_lst_printf	*last;

	last = ft_lstlast_printf(*lst);
	if (last == NULL)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}

void	ft_lstclear_printf(t_lst_printf **lst, void (*del)(void*))
{
	t_lst_printf	*begin;
	t_lst_printf	*tmp;

	if (lst == NULL)
		return ;
	begin = *lst;
	while (begin != NULL)
	{
		del(begin->content);
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	*lst = NULL;
}

int	ft_lstadd_new(char *res, size_t len, t_lst_printf **list)
{
	t_lst_printf	*new;

	new = ft_lstnew_printf(res, len);
	if (new == 0)
		return (0);
	ft_lstadd_back_printf(list, new);
	return (1);
}
