/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:38:33 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/25 02:00:23 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	char	c;
	char	*move;

	c = data->map[data->x_p - 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->x_p--;
		data->map[data->x_p][data->y_p] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
		move = ft_itoa(data->n_m);
		write(1, "Move : ", 8);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_down(t_data *data)
{
	char	c;
	char	*move;

	c = data->map[data->x_p + 1][data->y_p];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->x_p++;
		data->map[data->x_p][data->y_p] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
		move = ft_itoa(data->n_m);
		write(1, "Move : ", 8);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_left(t_data *data)
{
	char	c;
	char	*move;

	c = data->map[data->x_p][data->y_p - 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->y_p--;
		data->map[data->x_p][data->y_p] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
		move = ft_itoa(data->n_m);
		write(1, "Move : ", 8);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}

void	move_right(t_data *data)
{
	char	c;
	char	*move;

	c = data->map[data->x_p][data->y_p + 1];
	if (c != '1' && c != 'E')
	{
		if (c == 'C')
			data->collectible--;
		data->map[data->x_p][data->y_p] = '0';
		get_img(data, data->x_p, data->y_p);
		data->y_p++;
		data->map[data->x_p][data->y_p] = 'P';
		get_img(data, data->x_p, data->y_p);
		data->n_m++;
		move = ft_itoa(data->n_m);
		write(1, "Move : ", 8);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
	}
	if (c == 'E' && data->collectible == 0)
		ft_winner();
}
