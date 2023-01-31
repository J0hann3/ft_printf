/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:04:06 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/17 11:15:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_unsigned(unsigned int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	unsigned_to_string(unsigned int nb, t_lst_printf **list)
{
	char			*res;
	size_t			len;
	size_t			i;

	len = len_unsigned(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = 0;
	i = len - 1;
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (ft_lstadd_new(res, len, list));
}

int	hexa_to_string(unsigned int nb, t_lst_printf **list)
{
	char			*res;
	size_t			len;
	size_t			i;
	int				tmp;

	len = len_hex(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = 0;
	i = len - 1;
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		tmp = nb % 16;
		if (tmp > 9)
			res[i] = tmp - 10 + 'a';
		else
			res[i] = tmp + '0';
		nb = nb / 16;
		i--;
	}
	return (ft_lstadd_new(res, len, list));
}

int	hexa_to_string_maj(unsigned int nb, t_lst_printf **list)
{
	char			*res;
	size_t			len;
	size_t			i;
	int				tmp;

	len = len_hex(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = 0;
	i = len - 1;
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		tmp = nb % 16;
		if (tmp > 9)
			res[i] = tmp - 10 + 'A';
		else
			res[i] = tmp + '0';
		nb = nb / 16;
		i--;
	}
	return (ft_lstadd_new(res, len, list));
}

int	ft_itoa_lst(int nb, t_lst_printf **list)
{
	char			*res;
	size_t			len;
	size_t			i;
	unsigned int	n;

	if (nb >= 0)
		return (unsigned_to_string((unsigned int)nb, list));
	n = nb * -1;
	len = len_unsigned(n) + 1;
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[0] = '-';
	res[len] = 0;
	i = len - 1;
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (ft_lstadd_new(res, len, list));
}
