/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ddel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:01:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/02 18:01:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_str_ddel(char ***s)
{
	int		i;
	char	**str;

	if (!(*s))
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	str = *s;
	i = 0;
	while ((str[i]))
	{
		ft_strdel(&str[i]);
		str[i] = NULL;
		i++;
	}
	free(*s);
	*s = NULL;
}