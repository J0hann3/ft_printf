/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:46:57 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/12 12:02:03 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_charset(char c, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	long int	i;
	size_t		begin;
	size_t		end;

	i = 0;
	while (s1[i] && in_charset(s1[i], set) == 1)
		i++;
	begin = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && in_charset(s1[i], set) == 1)
		i--;
	end = i + 1;
	if (end < begin)
		end = 0;
	else
		end = end - begin;
	res = malloc(sizeof(char) * (end + 1));
	if (res == 0)
		return (0);
	i = -1;
	while (++i < (long int)end)
		res[i] = s1[begin + i];
	res[i] = 0;
	return (res);
}
