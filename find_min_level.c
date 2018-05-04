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
#include <stdio.h>

char		*find_min_level(int **table, t_rooms *room, int index, int size)
{
	int		i;
	int		min;
	int		min_index;

	min_index = 1;
	min = table[index][1];
	// printf("enter=%d\n", min);
	i = 1;
	while (i < size)
	{
		if (table[index][i] != 0)
		{
			if (min > table[index][i] || min == 0)
			{
				// printf("minim=%d\n", min);
				min = table[index][i];
				min_index = i;
			}
		}
		i++;
	}
	// printf("min=%d\n", min);
	min = table[0][min_index];
	// printf("min=%d\n", min);
	while (room != NULL)
	{
		if (room->index == min)
			return (room->room[0]);
		room = room->next;
	}
	return ("-");
}