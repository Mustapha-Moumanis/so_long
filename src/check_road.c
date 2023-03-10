/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:40:49 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/26 02:06:19 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible(char **copy_map, int i, int j)
{
	int	c;

	c = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'C')
				c++;
			j++;
		}
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
	if (c != 0)
		ft_error("\033[0;31myou can not eat a collectible\n");
}

void	check_exit(char **map, int i, int j)
{
	int	e;

	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
	if (e != 0)
		ft_error("\033[0;31myou can not exit\n");
}

void	flood_fill(char **copy_map, int i, int j, int r)
{
	int		c;
	char	s;

	s = copy_map[i][j];
	c = ft_strlen(copy_map[0]);
	if (i <= 0 || j <= 0 || i > r - 1 || j > c - 1
		|| s == '*' || s == '1' || s == 'E')
		return ;
	else
	{
		copy_map[i][j] = '*';
		flood_fill(copy_map, i + 1, j, r);
		flood_fill(copy_map, i - 1, j, r);
		flood_fill(copy_map, i, j + 1, r);
		flood_fill(copy_map, i, j - 1, r);
	}
}

void	flood_fill2(char **map, int i, int j, int r)
{
	int		c;
	char	s;

	s = map[i][j];
	c = ft_strlen(map[0]);
	if (i <= 0 || j <= 0 || i > r - 1 || j > c - 1
		|| s == '*' || s == '1')
		return ;
	else
	{
		map[i][j] = '*';
		flood_fill2(map, i + 1, j, r);
		flood_fill2(map, i - 1, j, r);
		flood_fill2(map, i, j + 1, r);
		flood_fill2(map, i, j - 1, r);
	}
}

int	check_path(t_data *data, int r)
{
	char	**copy_map;
	char	**copy2_map;
	int		i;

	i = 0;
	copy_map = malloc((r + 1) * sizeof(char *));
	if (!copy_map)
		return (0);
	copy2_map = malloc((r + 1) * sizeof(char *));
	if (!copy2_map)
		return (0);
	while (data->map[i])
	{
		copy2_map[i] = ft_strdup(data->map[i]);
		copy_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy_map[r] = NULL;
	copy2_map[r] = NULL;
	flood_fill(copy_map, data->x_p, data->y_p, r);
	flood_fill2(copy2_map, data->x_p, data->y_p, r);
	check_collectible(copy_map, 0, 0);
	check_exit(copy2_map, 0, 0);
	return (0);
}
