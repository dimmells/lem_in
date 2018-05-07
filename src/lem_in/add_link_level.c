/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:33:30 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/03 15:33:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_all_index(t_rooms *room, t_links *link, int *index_a,
	int *index_b)
{
	*index_a = get_index(room, link->room_one);
	*index_b = get_index(room, link->room_two);
}

int			**add_link_level(int **table, char *curr, t_farm **farm, int level)
{
	t_links	*link;
	int		index_a;
	int		index_b;

	link = (*farm)->link;
	while (link != NULL)
	{
		if (ft_strequ(curr, link->room_one) || ft_strequ(curr, link->room_two))
		{
			get_all_index((*farm)->room, link, &index_a, &index_b);
			if (table[index_a][index_b] > level || table[index_a][index_b] == 0)
			{
				table[index_a][index_b] = level;
				table[index_b][index_a] = level;
				if (ft_strequ(curr, link->room_two))
					table = add_link_level(table, link->room_one, farm,
						level + 1);
				else
					table = add_link_level(table, link->room_two, farm,
						level + 1);
			}
		}
		link = link->next;
	}
	return (table);
}
