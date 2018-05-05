/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:01:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/04 14:01:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int			get_size(t_rooms *room)
{
	int		size;

	size = 1;
	while (room)
	{
		size++;
		room = room->next;
	}
	return (size);
}