/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:04:53 by kofujita          #+#    #+#             */
/*   Updated: 2024/08/24 17:49:28 by kofujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_file.h"

/**
 * すでに読み込み情報に存在する場合の処理
 *
 * 1. t_file* -> 引数で渡された情報
 * 2. t_string* -> 引数で渡された情報
 * 3. const char* -> 存在した場所
 *
 * r. int -> [0 => 処理成功] / [1 => 処理失敗]
 */
static int	prcess1(
				t_file *tf,
				t_string *df,
				const char *pnt);

/**
 * 読み込み情報に存在しない場合の処理
 *
 * 1. t_file* -> 引数で渡された情報
 * 2. t_string* -> 引数で渡された情報
 * 3. const char -> 探したい文字情報
 *
 * r. int -> [0 => 処理成功] / [1 => 処理失敗]
 */
static int	prcess2(
				t_file *tf,
				t_string *df,
				const char chr);

size_t	t_file_getline(
			t_file *tf,
			t_string *df,
			char chr)
{
	const char		*pnt;
	int				res;

	t_string_clear(df);
	pnt = t_string_find(tf->__stk, chr);
	if (pnt)
		res = prcess1(tf, df, pnt);
	else
		res = prcess2(tf, df, chr);
	return (res);
}

int	prcess1(
		t_file *tf,
		t_string *df,
		const char *pnt)
{
	int			res;
	const char	*begin;

	begin = t_string_c_str(tf->__stk);
	df = t_string_set(df, begin, pnt);
	if (!df)
		return (1);
	res = t_string_erase(tf->__stk, 0, (pnt - begin) + 1);
	return (res);
}

int	prcess2(
		t_file *tf,
		t_string *df,
		const char chr)
{
	char			*begin;
	ssize_t			res;

	const char *(end), *(pnt) = 0x00;
	begin = t_string_data(tf->__stk);
	end = begin + t_string_length(tf->__stk);
	if (!t_string_set(df, begin, end))
		return (1);
	while (!pnt)
	{
		res = read(tf->__fd, begin, T_FILE_BUFFER_SIZE);
		if (res == -1)
			return (1);
		if (!res)
			break ;
		tf->__stk->__length = res;
		pnt = t_string_find(tf->__stk, chr);
		if (!pnt)
			df = t_string_append(df, begin, begin + res);
		else
			df = t_string_append(df, begin, pnt);
		if (!df)
			return (1);
	}
	return (0);
}
