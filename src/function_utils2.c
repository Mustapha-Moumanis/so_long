/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:14:27 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/25 05:13:30 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	images(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			get_img(data, i, j);
			j++;
		}
		i++;
	}
}

void	get_map(char *file_name, t_list **lst)
{
	int		fd;
	char	*s;

	check_file_format(file_name);
	fd = open(file_name, O_RDONLY);
	while (1337)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		ft_lstadd_back(lst, ft_lstnew(s));
	}
}

void	player_img(t_data *data, int d)
{
	int		k;
	int		i;
	int		j;

	i = data->x_p * 75;
	j = data->y_p * 75;
	if (d == 0)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/p/p_u.xpm", &k, &k);
	else if (d == 1)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/p/p_d.xpm", &k, &k);
	else if (d == 2)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/p/p_l.xpm", &k, &k);
	else if (d == 3)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/p/p_r.xpm", &k, &k);
	if (!data->img)
		ft_error("\033[0;31myou have a problem in xpm img\n");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, j, i);
}

void	c_animation(t_data *data, int i, int j)
{
	int	k;
	int	c;

	c = data->c_animation;
	if (c == 0)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c1.xpm", &k, &k);
	else if (c == 1500)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c2.xpm", &k, &k);
	else if (c == 3000)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c3.xpm", &k, &k);
	else if (c == 4500)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c4.xpm", &k, &k);
	else if (c == 6000)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c5.xpm", &k, &k);
	else if (c == 7500)
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c6.xpm", &k, &k);
	if (!data->img)
		ft_error("\033[0;31myou have a problem in xpm img\n");
	if (c == 0 || c == 1500 || c == 3000 || c == 4500 || c == 6000 || c == 7500)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, j, i);
	if (c > 7500)
		data->c_animation = 0;
}
