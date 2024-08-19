/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:32:28 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/03 17:19:21 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_file.h"

t_file	*t_file_open(
			const char *filename,
			int oflag)
{
	t_file		*ret;
	t_string	*stk;
	int			fd;

	fd = open(filename, oflag);
	if (fd < 0)
		return (NULL);
	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret)
		return (close(fd), NULL);
	stk = t_string_init();
	if (!stk)
		return (close(fd), free(ret), NULL);
	t_string_resize(stk, T_FILE_BUFFER_SIZE);
	if (!stk)
		return (close(fd), free(ret), NULL);
	ret->__fd = fd;
	ret->__stk = stk;
	return (ret);
}
