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

int			main(int ac, char **av)
{
	t_farm	*farm;
	t_rooms	*room;
	t_links	*link;
	t_map	*map;
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
	link = farm->link;
	// while (link)
	// {
	// 	printf("%s %s\n", link->room_one, link->room_two);
	// 	link = link->next;
	// }
	// i = 0;
	// while (i < size)
	// {
	// 	j = 0;
	// 	while (j < size)
	// 	{
	// 		printf("%d ", table[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	find_way(&farm, size, table);
	print_way(farm);
	free_all(&farm);
	// system("leaks a.out");
	return (0);
}