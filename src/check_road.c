/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:40:49 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/25 02:11:28 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	flood_fill(char **copy_map, int i, int j, int r)
{
	int		c;
	char	s;

	s = copy_map[i][j];
	c = ft_strlen(copy_map[0]);
	if (i <= 0 || j <= 0 || i > r - 1 || j > c - 1
		|| s == '*' || s == '1')
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

void	check_path(t_data *data, int r)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc((r + 1) * sizeof(char *));
	while (data->map[i])
	{
		copy_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy_map[r] = NULL;
	flood_fill(copy_map, data->x_p, data->y_p, r);
	check_way(copy_map, 0, 0);
}
