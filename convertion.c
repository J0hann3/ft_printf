/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:35:20 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/17 11:15:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_to_string(int c, t_lst_printf **list)
{
	t_lst_printf	*new;
	char			*res;

	res = malloc(sizeof(char) * 2);
	if (res == 0)
		return (0);
	res[0] = (unsigned char)c;
	res[1] = '\0';
	new = ft_lstnew_printf(res, 1);
	if (new == 0)
		return (0);
	ft_lstadd_back_printf(list, new);
	return (1);
}

int	string_to_string(char *str, t_lst_printf **list)
{
	char			*res;
	t_lst_printf	*new;

	if (str == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(str);
	if (res == 0)
		return (0);
	new = ft_lstnew_printf(res, ft_strlen(res));
	if (new == 0)
		return (0);
	ft_lstadd_back_printf(list, new);
	return (1);
}

size_t	len_hex(unsigned long int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	exception(t_lst_printf **list)
{
	char	*res;

	res = ft_strdup("(nil)");
	if (res == 0)
		return (0);
	return (ft_lstadd_new(res, 5, list));
}

int	pointeur_to_string(unsigned long int nb, t_lst_printf **list)
{
	char			*res;
	size_t			len;
	size_t			i;

	if (nb == 0)
		return (exception(list));
	len = len_hex(nb) + 2;
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[0] = '0';
	res[1] = 'x';
	res[len] = 0;
	i = len - 1;
	while (nb > 0)
	{
		if (nb % 16 > 9)
			res[i] = (nb % 16) + 'a' - 10;
		else
			res[i] = (nb % 16) + '0';
		nb = nb / 16;
		i--;
	}
	return (ft_lstadd_new(res, len, list));
}
