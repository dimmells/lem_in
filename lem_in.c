/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:29:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/01 11:29:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int 	is_rooms_exist(t_rooms *room, char *room_one, char *room_two)
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
int			main(int ac, char **av)
{
	t_farm	*farm;
	t_rooms	*room;
	t_links	*link;
	t_map	*map;
	t_way	*way;
	int		size;
	int		i;
	int		j;
	int		**table;

	farm = read_all();
	
	// printf("ants: %d\n", farm->ants);
	// printf("start: %s %s %s\n", farm->start[0], farm->start[1], farm->start[2]);
	// printf("end: %s %s %s\n", farm->end[0], farm->end[1], farm->end[2]);

	size = get_size(farm->room);
	table = create_table(farm->room, size);
	table = add_link_level(table, farm->start[0], &farm, 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", table[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


	int index = get_index(farm->room, farm->end[0]);
	i = 1;
	j = 0;
	while (i < size)
	{
		if (table[index][i] == 0)
			j++;
		i++;
	}
	if (j == i - 1)
	{
	  	ft_putendl_fd("ERROR", 2);
		// system("leaks a.out");
		exit(1);
	}

	link = farm->link;
	while (link)
	{
		// printf("%s %s\n", link->room_one, link->room_two);
		if (!is_rooms_exist(farm->room, link->room_one, link->room_two)
			|| ft_strequ(link->room_one, link->room_two))
		{
			ft_putendl_fd("ERROR", 2);
			// system("leaks a.out");
			exit(1);
		}
		link = link->next;
	}
	find_way(&farm, size, table);
	way = farm->way;
	while (way != NULL)
	{
		printf("%s\n", way->room);
		way = way->next;
	}
	room = farm->room;
	t_rooms *rd;
	while (room)
	{
		rd = farm->room;
		while (rd != NULL)
		{
			if (rd->index != room->index)
				if (ft_strequ(rd->room[0], room->room[0]))
				{
					ft_putendl_fd("ERROR", 2);
					// system("leaks a.out");
					exit(1);					
				}
			rd = rd->next;
		}
		room = room->next;
	}
	print_way(farm);
	free_all(&farm);
	system("leaks a.out");
	return (0);
}