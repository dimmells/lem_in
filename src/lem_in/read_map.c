/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:04:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/07 14:07:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_split_len(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

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

static int	check_hash(char *line, int is_room, int count)
{
	char	**split;
	char	**split_1;

	if (!(ft_strlen(line) > 1 && line[0] == '#' && line[1] != '#'))
	{
		split = ft_strsplit(line, ' ');
		if (ft_split_len(split) == 3 && is_room == 0)
			ft_exit();
		if (ft_split_len(split) != 3)
		{
			split_1 = ft_strsplit(line, '-');
			if (ft_split_len(split_1) == 2)
				is_room = 0;
			ft_str_ddel(&split_1);
		}
		ft_str_ddel(&split);
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			count++;
		if (ft_strequ(line, ""))
			ft_exit();
		if (ft_strlen(line) > 0 && line[0] == 'L')
			ft_exit();
	}
	return (count);
}

static void	check_part_two(char *line, int i)
{
	char	**split;
	char	**split_1;

	if (ft_strlen(line) > 0 && line[0] != '#' && i > 0)
	{
		split = ft_strsplit(line, ' ');
		split_1 = ft_strsplit(line, '-');
		if (ft_split_len(split) != 3)
			if (ft_split_len(split_1) != 2)
				ft_exit();
		ft_str_ddel(&split);
		ft_str_ddel(&split_1);
	}
}

t_map		*read_map(void)
{
	t_map	*map;
	char	*line;
	int		count;
	int		is_room;
	int		i;

	count = 0;
	is_room = 1;
	i = 0;
	while (get_next_line(0, &line))
	{
		check_part_two(line, i);
		count = check_hash(line, is_room, count);
		add_line(&map, ft_strdup(line));
		ft_strdel(&line);
		i++;
	}
	if (count != 2)
		ft_exit();
	return (map);
}
