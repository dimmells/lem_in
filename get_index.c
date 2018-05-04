/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:42:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/03 15:42:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_index(t_rooms *room, char *curr)
{
	while (room != NULL)
	{
		if (ft_strequ(room->room[0], curr))
		{
			return (room->index);
		}
		room = room->next;
	}
	return (0);
}
