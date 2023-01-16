/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:18 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/16 03:03:39 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_error(char *error_msg)
{
	printf("Error\n%s\n", error_msg);
	exit(1);
}

void	check_char(char **map, int len)
{
	int	i;
	int	j;
	char *set;

	i = 0;
	set = "10PCE\n";
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(set, map[i][j]))
				ft_error("Use the valid characters (0, 1, P, C, E)");
			j++;
		}
		i++;
	}
}

void	check_newline(char **ptr, char *last_line)
{
	int	i;

	i = 0;
	if (last_line[ft_strlen(last_line) - 1] == '\n')
		ft_error("You have a newline in the last line");
	while (ptr[i])
	{
		if (!ptr[i][0])
			ft_error("You have a duplicate newline");
		i++;
	}
}


void	check_len(char **ptr)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[i])
	{
		j = ft_strlen(ptr[i]);
		if (j < len || j > len)
			ft_error("The length of the lines is different");		
		i++;
	}
	if (j < 3)
		ft_error("At least three characters");
	if (i < 3)
		ft_error("At least three lines");
}

void check_duplicate(char **ptr)
{
	t_map	data;
	int	i;
	int	j;
	
	data.player = 0;
	data.collectible = 0;
	data.exit = 0;
	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'P')
				data.player++;
			if (ptr[i][j] == 'E')
				data.exit++;
			if (ptr[i][j] == 'C')
				data.collectible++;
			j++;
		}
		i++;
	}
	if (data.player != 1)
		ft_error("The map must contain 1 player");
	if (data.exit != 1)
		ft_error("The map must contain 1 exit");
	if (data.collectible < 1)
		ft_error("The map must contain least 1 collectible");
}

void	check_wall(char **ptr, int col_len, int row_len)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] != '1')
			{
				if (i == 0 || j == 0 || j == col_len - 1 || i == row_len - 1)
					ft_error("You have a problem in the wall");
			}
			j++;
		}
		i++;
	}
}

void	check_map(char **map, int len, char *last_line)
{
	check_char(map, len);
	check_newline(map, last_line);
	check_len(map);
	check_wall(map, ft_strlen(map[0]), len);
	check_duplicate(map);
}