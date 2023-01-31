/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:39:14 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/14 11:22:55 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	j;
	size_t	cpt;

	i = 0;
	j = 0;
	cpt = ft_strlen(src);
	while (n > 0 && dest[i] != '\0')
	{
		n--;
		i++;
	}
	if (n == 0)
		return (cpt + n + i);
	while ((j < n - 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (i + (cpt - j));
}
