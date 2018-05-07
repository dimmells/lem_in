/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:31:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/07 14:31:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "src/gnl/get_next_line.h"
# include "src/libft/libft.h"

typedef struct		s_links
{
	char			*room_one;
	char			*room_two;
	struct s_links	*next;
}					t_links;

typedef struct		s_rooms
{
	int				index;
	char			**room;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_way
{
	char			*room;
	int				ant;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way;

typedef struct		s_farm
{
	t_way			*way;
	t_map			*map;
	t_rooms			*room;
	t_links			*link;
	int				ants;
	char			**start;
	char			**end;
}					t_farm;

void				add_room(t_rooms **rooms, char **room);
void				add_link(t_links **links, char **link);
void				ft_str_ddel(char ***s);
void				free_all(t_farm **farm);
void				add_way(t_way **way, char *room);
void				find_way(t_farm **farm, int size, int **table);
void				print_way(t_farm *farm);
void				check(int **table, int size, t_farm *farm);
void				ft_exit();
int					**add_link_level(int **table, char *curr, t_farm **farm,
	int level);
t_map				*read_map(void);
t_farm				*read_all(void);
int					get_index(t_rooms *room, char *curr);
int					**create_table(t_rooms *room, int size);
int					get_size(t_rooms *room);
int					is_ants_in_room(t_way *way);
char				*find_min_level(int **table, t_rooms *room, int index,
	int size);

#endif
