/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:42:06 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/24 18:23:04 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_file.h"

size_t	t_file_gets(
			t_file *tf,
			t_string *dt,
			size_t n)
{
	ssize_t		res;
	char		*begin;

	t_string_clear(dt);
	while (t_string_length(tf->__stk) < n)
	{
		begin = t_string_data(tf->__stk);
		if (!t_string_append(dt, begin, begin + t_string_length(tf->__stk)))
			return ((size_t)(-1));
		res = read(tf->__fd, begin, T_FILE_BUFFER_SIZE);
		if (res == -1)
			return ((size_t)(-1));
		tf->__stk->__length = res;
		if (!res)
			break ;
	}
	begin = t_string_data(tf->__stk);
	if (!t_string_append(dt, begin, begin + n))
		return ((size_t)(-1));
	if (!t_string_push_back(dt, 0x00))
		return ((size_t)(-1));
	t_string_erase(tf->__stk, 0, n % T_FILE_BUFFER_SIZE);
	return (t_string_length(dt));
}
