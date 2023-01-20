/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:38:33 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/20 16:51:36 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void print_move(t_data *data)
{
	char	*str;
	
	str = ft_itoa(data->n_m);
	mlx_string_put(data->mlx, data->mlx_win, 37, 37, 0xFF0000, str);
	free(str);
}

void	move_up(t_data *data)
{
	char	c;

	c = data->map[data->x_p - 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		data->map[data->x_p - 1][data->y_p] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->x_p--;
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}
void	move_down(t_data *data)
{
	char c;

	c = data->map[data->x_p + 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		data->map[data->x_p + 1][data->y_p] = 'P';
				get_img(data, data->x_p, data->y_p);
		data->x_p++;
				get_img(data, data->x_p, data->y_p);
		data->n_m++;
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}
void	move_left(t_data *data)
{
	char c;

	c = data->map[data->x_p][data->y_p - 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		data->map[data->x_p][data->y_p - 1] = 'P';
				get_img(data, data->x_p, data->y_p);
		data->y_p--;
				get_img(data, data->x_p, data->y_p);
		data->n_m++;
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}
void	move_right(t_data *data)
{
	char c;

	c = data->map[data->x_p][data->y_p + 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		data->map[data->x_p][data->y_p + 1] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->y_p++;
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}