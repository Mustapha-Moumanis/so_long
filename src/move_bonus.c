/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:38:33 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/26 01:34:47 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	char	c;

	c = data->map[data->x_p - 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C' && c > 0)
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->x_p--;
		data->map[data->x_p][data->y_p] = 'P';
		data->n_m++;
	}
	player_img(data, 0);
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_down(t_data *data)
{
	char	c;

	c = data->map[data->x_p + 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C' && c > 0)
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->x_p++;
		data->map[data->x_p][data->y_p] = 'P';
		data->n_m++;
	}
	player_img(data, 1);
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_left(t_data *data)
{
	char	c;

	c = data->map[data->x_p][data->y_p - 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C' && c > 0)
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->y_p--;
		data->map[data->x_p][data->y_p] = 'P';
		data->n_m++;
	}
	player_img(data, 2);
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_right(t_data *data)
{
	char	c;

	c = data->map[data->x_p][data->y_p + 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C' && c > 0)
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->y_p++;
		data->map[data->x_p][data->y_p] = 'P';
		data->n_m++;
	}
	player_img(data, 3);
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}
