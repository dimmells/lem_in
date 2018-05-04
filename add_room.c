/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:50:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/01 12:50:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room(t_rooms **rooms, char **room)
{
	t_rooms	*lst;
	t_rooms	*new;
	int		j;

	new = (t_rooms*)malloc(sizeof(t_rooms));
	new->room = room;
	new->next = NULL;
	lst = *rooms;
	if (lst)
	{
		j = 2;
		while (lst->next)
		{
			lst = lst->next;
			j++;
		}
		new->index = j;
		lst->next = new;
	}
	else
	{
		new->index = 1;
		*rooms = new;
	}
}