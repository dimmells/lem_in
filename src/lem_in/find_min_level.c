/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:27:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/04 12:27:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*find_min_level(int **table, t_rooms *room, int index, int size)
{
	int		i;
	int		min;
	int		min_index;

	min_index = 1;
	min = table[index][1];
	i = 1;
	while (i < size)
	{
		if (table[index][i] != 0)
			if (min > table[index][i] || min == 0)
			{
				min = table[index][i];
				min_index = i;
			}
		i++;
	}
	min = table[0][min_index];
	while (room != NULL)
	{
		if (room->index == min)
			return (room->room[0]);
		room = room->next;
	}
	return ("-");
}
