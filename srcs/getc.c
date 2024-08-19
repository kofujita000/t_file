/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:42:06 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/03 17:17:04 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_file.h"

char	t_file_getc(
			t_file *tf)
{
	char		ret;
	size_t		res;

	if (!t_string_size(tf->__stk))
	{
		res = read(tf->__fd, t_string_data(tf->__stk), T_FILE_BUFFER_SIZE);
		if (res == -1 || res == 0)
			return (0x00);
	}
	ret = *t_string_c_str(tf->__stk);
	t_string_erase(tf->__stk, 0, 1);
	return (ret);
}
