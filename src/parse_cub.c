/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 17:17:21 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		error_parsing(void)
{
	ft_putstr_fd("Error\nUn problème est survenu lors du parsing.\n\
Merci de vérifier la validité du ficher .cub", 1);
	return (1);
}

int		parse_cub(int fd, t_stru *stru)
{
	char	*line;
	char	*map;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (count <= 8 && get_next_line(fd, &line) > 0)
	{
		count = analyse_line(line, stru, i);
		free(line);
	}
	if (count < 9)
		ft_putstr_fd("Error\n", 1);
	if (count < 9)
		return (1);
	while (get_next_line(fd, &line) > 0)
		map = strjoin_free_nl(map, line);
	if ((tab_to_matrix(stru, map)) || check_stru(stru) || check_map(stru))
		return (error_parsing());
	return (0);
}
