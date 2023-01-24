/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/24 22:56:09 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"

void	get_img(t_data *data, int i, int j)
{
	int		k;
	int		c;
	int		r;

	c = data->col_len - 1;
	r = data->row_len - 1;
	data->x = i * 75;
	data->y = j * 75;
	if (data->map[i][j] == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/p/p_u.xpm", &k, &k);
	else if (data->map[i][j] == '0')
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/img/s_0.xpm", &k, &k);
	else if (data->map[i][j] == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/c/c1.xpm", &k, &k);
	else if (data->map[i][j] == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/img/s_d.xpm", &k, &k);
	else
		data->img = mlx_xpm_file_to_image(data->mlx, "utils/img/s_w.xpm", &k, &k);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->y, data->x);
}

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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 126 || keycode == 13)
		move_up(data);
	else if (keycode == 125 || keycode == 1)
		move_down(data);
	else if (keycode == 123 || keycode == 0)
		move_left(data);
	else if (keycode == 124 || keycode == 2)
		move_right(data);
	else if (keycode == 53)
		ft_close();
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
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
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

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
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
	tmp = lst;
	i = 0;
	while (tmp)
	{
		data.map[i] = ft_strtrim(tmp->content, "\n");
		printf("%s\n", data.map[i]);
		tmp = tmp->next;
		i++;
	}
	data.map[i] = NULL;
	check_map(ft_lstsize(lst), (ft_lstlast(lst))->content, &data);
	// system("leaks so_long");
	graphic(i, ft_strlen(data.map[0]), &data);
}
