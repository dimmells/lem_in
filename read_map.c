/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:04:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/03 12:04:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	add_line(t_map **map, char *line)
{
	t_map	*lst;
	t_map	*new;

	new = (t_map*)malloc(sizeof(t_map));
	new->line = line;
	new->next = NULL;
	lst = *map;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*map = new;
}

t_map		*read_map(void)
{
	t_map	*map;
	char	*line;

	map = NULL;
	while (get_next_line(0, &line))
	{
		add_line(&map, ft_strdup(line));
		ft_strdel(&line);
	}
	return(map);
}