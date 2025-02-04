/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:39:12 by kofujita          #+#    #+#             */
/*   Updated: 2024/09/16 22:44:56 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_file.h"

void	t_file_close(
			t_file *tf)
{
	(void)(tf && 0 <= tf->__fd && close(tf->__fd));
	(void)(tf && tf->__stk && (t_string_free(tf->__stk), 0));
	free(tf);
}
