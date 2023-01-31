/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <johanne.vgn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:49:57 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/11 17:49:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin;
	t_list	*tmp;

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
