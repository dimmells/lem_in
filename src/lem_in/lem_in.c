/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:29:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/01 11:29:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_farm	*farm;
	t_map	*map;
	int		size;
	int		**table;

	farm = read_all();
	size = get_size(farm->room);
	table = create_table(size);
	table = add_link_level(table, farm->start[0], &farm, 1);
	check(table, size, farm);
	find_way(&farm, size, table);
	map = farm->map;
	while (map != NULL)
	{
		ft_putendl(map->line);
		map = map->next;
	}
	ft_putstr("\n");
	print_way(farm);
	return (0);
}
