/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:18 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/20 21:07:27 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

// void	check_path(char **copy_map, t_data *data, int col_len, int row_len)
// {
// 	(void)col_len;
// 	(void)row_len;
// 	(void)data;
// 	copy_map[0][0] = '1';
// 	printf("%c\n", copy_map[0][0]);
// }

void	check_map(int row_len, char *last_line, t_data *data)
{
	int	col_len;
	// char *copy_map, 
	col_len = ft_strlen(data->map[0]);
	check_char(row_len, data);
	check_newline(data->map, last_line);
	check_len(data->map);
	check_wall(data->map, col_len, row_len, data);
	check_duplicate(data->map, data);
	// check_path(&copy_map, data, col_len, row_len);
}
