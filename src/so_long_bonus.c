/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:15:24 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/25 05:13:30 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"

void	get_img(t_data *d, int i, int j)
{
	int		k;
	int		c;
	int		r;

	c = d->col_len - 1;
	r = d->row_len - 1;
	d->x = i * 75;
	d->y = j * 75;
	if (d->map[i][j] == 'P')
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/p/p_u.xpm", &k, &k);
	else if (d->map[i][j] == '0')
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/img/s_0.xpm", &k, &k);
	else if (d->map[i][j] == 'C')
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/c/c1.xpm", &k, &k);
	else if (d->map[i][j] == 'E' && d->collectible != 0)
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/img/d_c.xpm", &k, &k);
	else if (d->map[i][j] == 'E' && d->collectible == 0)
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/img/s_d.xpm", &k, &k);
	else
		d->img = mlx_xpm_file_to_image(d->mlx, "utils/img/s_w.xpm", &k, &k);
	if (!d->img)
		ft_error("\033[0;31myou have a problem in xpm img\n");
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, d->y, d->x);
}

int	animation(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				c_animation(data, i * 75, j * 75);
			j++;
		}
		i++;
	}
	data->c_animation++;
	return (0);
}

int	key_hook(int keycode, t_data *d)
{
	char	*c;

	if (keycode == 126 || keycode == 13)
		move_up(d);
	else if (keycode == 125 || keycode == 1)
		move_down(d);
	else if (keycode == 123 || keycode == 0)
		move_left(d);
	else if (keycode == 124 || keycode == 2)
		move_right(d);
	else if (keycode == 53)
		ft_close();
	get_img(d, d->x_e, d->y_e);
	c = ft_itoa(d->n_m);
	get_img(d, 0, 0);
	mlx_string_put(d->mlx, d->mlx_win, 25, 25, 0x00FFFF, c);
	free(c);
	return (1);
}

void	graphic(int col_len, int row_len, t_data *data)
{
	data->col_len = col_len;
	data->row_len = row_len;
	row_len *= 75;
	col_len *= 75;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, row_len, col_len, "so_long");
	images(data);
	mlx_string_put(data->mlx, data->mlx_win, 25, 25, 0x00FFFF, "0");
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_data	data;
	int		i;

	lst = NULL;
	if (argc < 2)
		return (0);
	data = (t_data){0};
	get_map(argv[1], &lst);
	if (!lst)
		return (0);
	data.map = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!data.map)
		return (0);
	data.tmp = lst;
	i = 0;
	while (data.tmp)
	{
		data.map[i] = ft_strtrim(data.tmp->content, "\n");
		data.tmp = data.tmp->next;
		i++;
	}
	data.map[i] = NULL;
	check_map(ft_lstsize(lst), (ft_lstlast(lst))->content, &data);
	graphic(i, ft_strlen(data.map[0]), &data);
}
