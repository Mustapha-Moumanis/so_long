/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/17 01:42:27 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"
#include <mlx.h>

void	images(char c, t_data *data)
{
	int		k;

	if (c == '1')
	data->img = mlx_xpm_file_to_image(data->mlx, "./utils/wall_75.xpm", &k, &k);
	if (c == '0')
	data->img = mlx_xpm_file_to_image(data->mlx, "./utils/empty.xpm", &k, &k);
	if (c == 'C')
	data->img = mlx_xpm_file_to_image(data->mlx, "./utils/eat.xpm", &k, &k);
	if (c == 'E')
	data->img = mlx_xpm_file_to_image(data->mlx, "./utils/o_door.xpm", &k, &k);
	if (c == 'P')
	data->img = mlx_xpm_file_to_image(data->mlx, "./utils/sumo.xpm", &k, &k);
}

void	graphic(char **map, int col_len, int row_len, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	row_len *= 75;
	col_len *= 75;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, row_len, col_len, "so_long");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			x = i * 75;
			y = j * 75;
			images(map[i][j], data);
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, y, x);
			j++;
		}
		i++;
	}
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
	char	**map;
	t_data	data;
	int		i;

	lst = NULL;
	if (argc < 2)
		return (0);
	data = (t_data){0};
	get_map(argv[1], &lst);
	tmp = lst;
	if (!lst)
		return (0);
	map = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (tmp)
	{
		map[i] = ft_strtrim(tmp->content, "\n");
		printf("%s\n", map[i]);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	check_map(map, ft_lstsize(lst), (ft_lstlast(lst))->content, &data);
	// system("leaks so_long");
	graphic(map, i, ft_strlen(map[0]), &data);
}
