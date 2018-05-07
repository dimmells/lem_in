/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:50:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/04 13:50:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				**create_table(int size)
{
	int			j;
	int			i;
	int			**table;

	table = (int**)malloc(sizeof(int*) * (size));
	i = 0;
	while (i < size)
	{
		table[i] = (int*)malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
		{
			table[i][j] = 0;
			j++;
		}
		i++;
	}
	j = 1;
	while (j < size)
	{
		table[0][j] = j;
		table[j][0] = j;
		j++;
	}
	return (table);
}
