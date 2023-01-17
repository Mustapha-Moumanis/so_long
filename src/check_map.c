/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:18 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/17 01:24:11 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_char(char **map, int len, t_data *data)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "10PCE\n";
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(set, map[i][j]))
				ft_error("Use the valid characters (0, 1, P, C, E)");
			if (map[i][j] == 'E')
			{
				data->x_e = i;
				data->y_e = j;
			}
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
	data->x_p = 0;
	data->y_p = 0;
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

void	check_map(char **map, int len, char *last_line, t_data *data)
{
	check_char(map, len, data);
	check_newline(map, last_line);
	check_len(map);
	check_wall(map, ft_strlen(map[0]), len, data);
	check_duplicate(map, data);
}
