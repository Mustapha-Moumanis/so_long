/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:38:33 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/19 01:46:10 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	char c;

	c = data->map[data->x_p - 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		data->map[data->x_p - 1][data->y_p] = 'P';
		data->x_p--;
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
		data->x_p++;
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
		data->y_p--;
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
		data->y_p++;
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}