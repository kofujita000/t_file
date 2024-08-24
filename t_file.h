/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:42:22 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/24 18:02:59 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FILE_H
# define T_FILE_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# include "../t_string/t_string.h"

# define T_FILE_BUFFER_SIZE 0x100

typedef struct s_file
{
	int			__fd;
	t_string	*__stk;
}	t_file;

/**
 * ファイルを開くための関数 (開いたら必ず閉じよう)
 *
 * 1. const char* -> ファイル名
 *
 * r. t_file* -> [NULL => ファイルを開くことに失敗] / [!NULL => ファイルを開くことに成功]
 */
t_file		*t_file_open(
				const char *filename,
				int oflag);

/**
 * ファイルを閉じるための関数
 *
 * 1. t_file* -> 閉じたいファイルの情報
 */
void		t_file_close(
				t_file *tf);

/**
 * ファイルから1文字取得するための関数
 *
 * 1. t_file* -> 開いたファイル情報
 *
 * r. char -> 取得した文字
 */
char		t_file_getc(
				t_file *tf);

/**
 * ファイルから複数文字列取得するための関数
 *
 * 1. t_file* -> 開いたファイル情報
 * 2. t_string* -> 書き込み先
 * 3. size_t -> 書き込み最大サイズ
 *
 * r. size_t -> 確保した文字列の長さ (SIZE_MAX が戻ってきたらエラー)
 */
size_t		t_file_gets(
				t_file *tf,
				t_string *dt,
				size_t n);

/**
 * ファイルから特定の文字が出現するまでの情報を取得するための関数
 *
 * 1. t_file* -> 開いたファイル情報
 * 2. t_string* -> 書き込み先
 * 3. char -> 特定の文字
 *
 * r. size_t -> 確保した文字列の長さ (SIZE_MAX が戻ってきたらエラー)
 */
size_t		t_file_getline(
				t_file *tf,
				t_string *df,
				char chr);

#endif // T_FILE_H
