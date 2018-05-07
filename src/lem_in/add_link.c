/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:50:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/01 12:50:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_links **links, char **link)
{
	t_links	*lst;
	t_links	*new;
	char	*room_one;
	char	*room_two;
	char	**split;

	room_one = ft_strdup(link[0]);
	room_two = ft_strdup(link[1]);
	new = (t_links*)malloc(sizeof(t_links));
	new->room_one = room_one;
	new->room_two = room_two;
	new->next = NULL;
	lst = *links;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*links = new;
	ft_str_ddel(&link);
}
