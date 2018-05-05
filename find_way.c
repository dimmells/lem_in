/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:46:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/05 13:46:57 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		find_way(t_farm **farm, int size, int **table)
{
	char	*way;
	int		index;

	way = (*farm)->end[0];
	while (!ft_strequ(way, (*farm)->start[0]))
	{
		if (!ft_strequ(way, (*farm)->end[0]))
			add_way(&(*farm)->way, way);
		index = get_index((*farm)->room, way);
		way = find_min_level(table, (*farm)->room, index, size);
	}
}