/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:42:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/05 11:42:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_way(t_way **way, char *room)
{
	t_way	*new;
	t_way	*lst;

	new = (t_way*)malloc(sizeof(t_way));
	new->room = room;
	new->ant = 0;
	new->next = NULL;
	new->prev = NULL;
	lst = *way;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		new->prev = lst;
		lst->next = new;
	}
	else
		*way = new;
}