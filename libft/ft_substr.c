/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:38:47 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/14 12:31:31 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	size_t			len_malloc;
	size_t			j;
	char			*res;

	j = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		len_malloc = 0;
	else
		len_malloc = len_s - start;
	if (len > len_malloc)
		res = malloc(sizeof(char) * (len_malloc + 1));
	else
	{
		res = malloc(sizeof(char) * (len + 1));
		len_malloc = len;
	}
	if (res == NULL)
		return (0);
	while (j < len_malloc)
		res[j++] = s[start++];
	res[j] = 0;
	return (res);
}
