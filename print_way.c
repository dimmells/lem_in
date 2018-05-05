/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:57:33 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/05 13:57:34 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_ant_and_room(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
}

static int		shift_ant(t_way **way, t_farm *farm, int j, int i)
{
	if ((*way)->prev == NULL)
	{
		print_ant_and_room((*way)->ant, farm->end[0]);
		(*way)->ant = 0;
		j++;
		if (farm->ants == j)
			return (j);
	}
	else
	{
		if (i != 1)
			ft_putchar(' ');
		print_ant_and_room((*way)->ant, (*way)->prev->room);
		(*way)->prev->ant = (*way)->ant;
		(*way)->ant = 0;
	}
	return (j);
}

static int		add_new_ant(t_way **way, t_farm *farm, int i)
{
	i++;
	if (i <= farm->ants)
	{
		if (i != 1)
			ft_putchar(' ');
		print_ant_and_room(i, (*way)->room);
		(*way)->ant = i;
	}
	return (i);
}

void			print_way(t_farm *farm)
{
	t_way		*way;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (farm->ants > j)
	{
		way = farm->way;
		while (way)
		{
			if (way->ant > 0)
			{
				j = shift_ant(&way, farm, j, i);
				if (farm->ants == j)
					break ;
			}
			if (way->next == NULL && way->ant == 0)
			{
				i = add_new_ant(&way, farm, i);
			}
			way = way->next;
		}
		ft_putstr("\n");
	}
}
