/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_t_file_getc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:24:14 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/24 17:50:47 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../t_file.h"

// 実在するファイル名
#define FILENAME00 "00_test_t_file_open.c"

static void	test(
				const int cnt,
				const char *filename);

int	main(int argc, char **argv)
{
	const char	*filename;

	test(0, FILENAME00);
}

void	test(
			const int cnt,
			const char *filename)
{
	t_file		*file;
	char		buf;

	printf("Test[%02d]: ", cnt);
	file = t_file_open(filename, O_RDONLY);
	if (!file)
		printf("Failed to open the file.(%s)\n", filename);
	else
	{
		while (buf)
		{
			buf = t_file_getc(file);
			printf("%c", buf);
		}
		t_file_close(file);
	}
}
