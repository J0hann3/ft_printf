/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:40:17 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/17 10:48:49 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertion_arg(char c, va_list elem, t_lst_printf **list)
{
	if (c == 'c')
		return (char_to_string(va_arg(elem, int), list));
	if (c == 's')
		return (string_to_string(va_arg(elem, char *), list));
	if (c == 'p')
		return (pointeur_to_string(va_arg(elem, unsigned long int), list));
	if (c == 'd')
		return (ft_itoa_lst(va_arg(elem, int), list));
	if (c == 'i')
		return (ft_itoa_lst(va_arg(elem, int), list));
	if (c == 'u')
		return (unsigned_to_string(va_arg(elem, unsigned int), list));
	if (c == 'x')
		return (hexa_to_string(va_arg(elem, unsigned int), list));
	if (c == 'X')
		return (hexa_to_string_maj(va_arg(elem, unsigned int), list));
	if (c == '%')
		return (char_to_string('%', list));
	return (0);
}

int	in_charset(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cpy_str(const char *str, size_t begin, size_t end, t_lst_printf **list)
{
	char			*res;
	size_t			i;
	t_lst_printf	*new;

	i = 0;
	res = malloc(sizeof(char) * (end - begin + 1));
	if (res == 0)
		return (0);
	while (i < (end - begin))
	{
		res[i] = ((char *)str)[begin + i];
		i++;
	}
	res[i] = 0;
	new = ft_lstnew_printf(res, end - begin);
	if (new == 0)
		return (0);
	ft_lstadd_back_printf(list, new);
	return (1);
}

int	ft_write(t_lst_printf *list)
{
	int				res;
	t_lst_printf	*new;

	res = 0;
	while (list != 0)
	{
		write(1, (list->content), list->len);
		res = res + list->len;
		free(list->content);
		new = list->next;
		free(list);
		list = new;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list			elem;
	t_lst_printf	*list;
	size_t			i;
	size_t			last;

	i = -1;
	last = 0;
	list = 0;
	va_start(elem, str);
	while (str[++i])
	{
		if (str[i] == '%' && in_charset("cspdiuxX%", str[i + 1]) == 1)
		{
			if (i > last && cpy_str(str, last, i, &list) == 0)
				return (ft_lstclear_printf(&list, free), -1);
			if (convertion_arg(str[++i], elem, &list) == 0)
				return (ft_lstclear_printf(&list, free), -1);
			last = i + 1;
		}
	}
	if (i > last && cpy_str(str, last, i, &list) == 0)
		return (ft_lstclear_printf(&list, free), -1);
	if (list == NULL)
		ft_putstr_fd((char *)str, 1);
	return (ft_write(list));
}
