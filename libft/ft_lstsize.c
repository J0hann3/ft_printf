/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:21:04 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/10 18:27:24 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		len++;
		lst = lst->next;
	}
	len++;
	return (len);
}
