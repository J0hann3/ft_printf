/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:58:22 by jvigny            #+#    #+#             */
/*   Updated: 2022/11/18 10:28:34 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_lst_printf
{
	char				*content;
	size_t				len;
	struct s_lst_printf	*next;
}	t_lst_printf;

t_lst_printf	*ft_lstnew_printf(char *content, size_t len);
t_lst_printf	*ft_lstlast_printf(t_lst_printf *lst);
void			ft_lstadd_back_printf(t_lst_printf **lst, t_lst_printf *new);
void			ft_lstclear_printf(t_lst_printf **lst, void (*del)(void*));
int				ft_lstadd_new(char *res, size_t len, t_lst_printf **list);
int				char_to_string(int c, t_lst_printf **list);
int				string_to_string(char *str, t_lst_printf **list);
size_t			len_hex(unsigned long int nb);
int				exception(t_lst_printf **list);
int				pointeur_to_string(unsigned long int nb, t_lst_printf **list);
size_t			len_unsigned(unsigned int nb);
int				unsigned_to_string(unsigned int nb, t_lst_printf **list);
int				hexa_to_string(unsigned int nb, t_lst_printf **list);
int				hexa_to_string_maj(unsigned int nb, t_lst_printf **list);
int				ft_itoa_lst(int nb, t_lst_printf **list);
int				convertion_arg(char c, va_list elem, t_lst_printf **list);
int				in_charset(const char *str, char c);
int				cpy_str(const char *str, size_t begin, size_t end,
					t_lst_printf **list);
int				ft_write(t_lst_printf *list);
int				ft_printf(const char *str, ...);

#endif