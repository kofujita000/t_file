/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_t_file_getline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:24:14 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/24 15:28:52 by kofujita         ###   ########.fr       */
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
	t_string	*str;

	printf("Test[%02d]: ", cnt);
	file = t_file_open(filename, O_RDONLY);
	if (!file)
		printf("Failed to open the file.(%s)\n", filename);
	else
	{
		str = t_string_init();
		t_file_getline(file, str, '\n');
		printf("%s\n", t_string_c_str(str));
		t_file_getline(file, str, '\n');
		printf("%s\n", t_string_c_str(str));
		t_string_free(str);
	}
	t_file_close(file);
}
