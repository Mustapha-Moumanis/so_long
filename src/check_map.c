/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:18 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/24 20:51:04 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"

void	check_char(int len, t_data *data)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "10PCE\n";
	while (i < len)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr(set, data->map[i][j]))
				ft_error("Use the valid characters (0, 1, P, C, E)");
			j++;
		}
		i++;
	}
}

void	check_duplicate(char **ptr, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'P')
				data->player++;
			if (ptr[i][j] == 'E')
				data->exit++;
			if (ptr[i][j] == 'C')
				data->collectible++;
			j++;
		}
		i++;
	}
	if (data->player != 1)
		ft_error("The map must contain 1 player");
	if (data->exit != 1)
		ft_error("The map must contain 1 exit");
	if (data->collectible < 1)
		ft_error("The map must contain least 1 collectible");
}

void	check_wall(char **ptr, int col_len, int row_len, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	// data->x_p = 0;
	// data->y_p = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] != '1')
			{
				if (i == 0 || j == 0 || j == col_len - 1 || i == row_len - 1)
					ft_error("You have a problem in the wall");
				if (ptr[i][j] == 'P')
				{
					data->x_p = i;
					data->y_p = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	check_way(char **copy_map, int i, int j)
{
	int	c;
	int	e;

	c = 0;
	e = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'C')
				c++;
			if (copy_map[i][j] == 'E')
				e++;
			j++;
		}
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
	if (c != 0)
		ft_error("you can not eat a collectible");
	if (e != 0)
		ft_error("you can not exit");
}

void	flood_fill(char **copy_map, int i, int j, int c, int r)
{
	if (i <= 0 || j <= 0 || i > r - 1 || j > c - 1
			|| copy_map[i][j] == '*' || copy_map[i][j] == '1')
		return;
	else
	{
		copy_map[i][j] = '*';
		flood_fill(copy_map, i + 1, j, c, r);
		flood_fill(copy_map, i - 1, j, c, r);
		flood_fill(copy_map, i, j + 1, c, r);
		flood_fill(copy_map, i, j - 1, c, r);
	}
}

void	check_path(t_data *data, int c, int r)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc((r + 1) * sizeof(char *));
	while  (data->map[i])
	{
		copy_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy_map[r] = NULL;
	flood_fill(copy_map, data->x_p, data->y_p, c, r);
	check_way(copy_map, 0, 0);
}

void	check_map(int row_len, char *last_line, t_data *data)
{
	int	col_len;

	col_len = ft_strlen(data->map[0]);
	check_char(row_len, data);
	check_newline(data->map, last_line);
	check_len(data->map);
	check_wall(data->map, col_len, row_len, data);
	check_duplicate(data->map, data);
	check_path(data, col_len, row_len);
}
