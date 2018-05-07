/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:54:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/07 12:54:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_rooms_exist(t_rooms *room, char *room_one, char *room_two)
{
	int		r1;
	int		r2;

	r1 = 0;
	r2 = 0;
	while (room != NULL)
	{
		if (ft_strequ(room->room[0], room_one))
			r1++;
		if (ft_strequ(room->room[0], room_two))
			r2++;
		room = room->next;
	}
	if (r1 > 0 && r2 > 0)
		return (1);
	return (0);
}

static void	check_is_way_exist(int **table, int size, t_farm *farm)
{
	int		index;
	int		i;
	int		j;

	index = get_index(farm->room, farm->end[0]);
	i = 1;
	j = 0;
	while (i < size)
	{
		if (table[index][i] == 0)
			j++;
		i++;
	}
	if (j == i - 1)
		ft_exit();
}

static void	check_link(t_farm *farm)
{
	t_links	*link;

	link = farm->link;
	while (link)
	{
		if (!is_rooms_exist(farm->room, link->room_one, link->room_two)
			|| ft_strequ(link->room_one, link->room_two))
			ft_exit();
		link = link->next;
	}
}

void		check(int **table, int size, t_farm *farm)
{
	t_rooms	*room;
	t_rooms	*rd;

	check_is_way_exist(table, size, farm);
	check_link(farm);
	room = farm->room;
	while (room)
	{
		rd = farm->room;
		while (rd != NULL)
		{
			if (rd->index != room->index)
				if (ft_strequ(rd->room[0], room->room[0]))
					ft_exit();
			rd = rd->next;
		}
		room = room->next;
	}
}
