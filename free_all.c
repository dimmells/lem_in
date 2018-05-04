/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:50:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/03 12:50:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_rooms(t_farm **farm)
{
	t_rooms		*room;

	room = (*farm)->room;
	while ((*farm)->room != NULL)
	{
		room = (*farm)->room->next;
		ft_str_ddel(&(*farm)->room->room);
		(*farm)->room->room = NULL;
		free((*farm)->room);
		(*farm)->room = NULL;
		(*farm)->room = room;		
	}
	free((*farm)->room);
	(*farm)->room = NULL;
}

static void		free_links(t_farm **farm)
{
	t_links		*link;

	link = (*farm)->link;
	while ((*farm)->link != NULL)
	{
		link = (*farm)->link->next;
		ft_strdel(&(*farm)->link->room_one);
		(*farm)->link->room_one = NULL;
		ft_strdel(&(*farm)->link->room_two);
		(*farm)->link->room_two = NULL;
		free((*farm)->link);
		(*farm)->link = NULL;
		(*farm)->link = link;
	}
	free((*farm)->link);
	(*farm)->link = NULL;
}

static void		free_map(t_farm **farm)
{
	t_map		*map;

	(*farm)->map = map;
	while ((*farm)->map != NULL)
	{
		map = (*farm)->map->next;
		ft_strdel(&(*farm)->map->line);
		(*farm)->map->line = NULL;
		free((*farm)->map);
		(*farm)->map = NULL;
		(*farm)->map = map;
	}
	free(map);
	(*farm)->map = NULL;
}

void			free_all(t_farm **farm)
{
	free_rooms(farm);
}