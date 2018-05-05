/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:59:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/03 12:59:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int		ft_split_len(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void		get_start_and_end(t_farm **farm)
{
	t_map		*map;

	map = (*farm)->map;
	while ((*farm)->map)
	{
		if (ft_strequ("##start", (*farm)->map->line))
		{
			(*farm)->map = (*farm)->map->next;
			(*farm)->start = ft_strsplit((*farm)->map->line, ' ');
			if (ft_split_len((*farm)->start) != 3)
			{
				ft_putendl_fd("ERROR", 2);
				// system("leaks a.out");
				exit(1);
			}
		}
		if (ft_strequ("##end", (*farm)->map->line))
		{
			(*farm)->map = (*farm)->map->next;
			(*farm)->end = ft_strsplit((*farm)->map->line, ' ');
			if (ft_split_len((*farm)->end) != 3)
			{
				ft_putendl_fd("ERROR", 2);
				// system("leaks a.out");
				exit(1);
			}
		}
		(*farm)->map = (*farm)->map->next;
	}
	(*farm)->map = map;
}

static void		reding(t_farm **farm)
{
	char		**split;

	while ((*farm)->map)
	{
		// if (ft_strequ((*farm)->map->line, ""))
		// 	break ;
		if (ft_strlen((*farm)->map->line) > 0
			&& (*farm)->map->line[0] != '#' && (*farm)->map->line[0] != 'L')
		{
			split = ft_strsplit((*farm)->map->line, ' ');
			if (ft_split_len(split) == 3)
			{
				add_room(&((*farm)->room),
				ft_strsplit((*farm)->map->line, ' '));
			}
			else if (ft_split_len(split) != 3)
			{
				add_link(&((*farm)->link),
				ft_strsplit((*farm)->map->line, '-'));
			}
			ft_str_ddel(&split);
		}
		(*farm)->map = (*farm)->map->next;
	}
}

t_farm			*read_all(void)
{
	t_farm		*farm;
	t_map		*map;
	int			i;

	farm = (t_farm*)malloc(sizeof(t_farm));
	farm->map = read_map();
	
	int count = 0;
	map = farm->map;
	while (map != NULL)
	{
		if (ft_strequ(map->line, "##start") || ft_strequ(map->line, "##end"))
			count++;
		map = map->next;
	}
	if (count != 2)
	{
		ft_putendl_fd("ERROR", 2);
		// system("leaks a.out");
		exit(1);
	}
	map = farm->map;
	while (map != NULL)
	{
		printf("%s\n", map->line);
		map = map->next;
	}



	map = farm->map;
	farm->room = NULL;
	farm->link = NULL;
	farm->way = NULL;
	farm->ants = ft_atoi(farm->map->line);
	farm->map = farm->map->next;
	get_start_and_end(&farm);
	reding(&farm);
	farm->map = map;
	return (farm);
}
