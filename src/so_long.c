/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/16 02:59:13 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"
#include <mlx.h>

void	graphic(char **map, int col_len, int row_len)
{
	int		i;
	int		j;
	int		k;
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, row_len * 50, col_len * 50, "so_long");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				data.img = mlx_xpm_file_to_image(data.mlx, "./utils/wall.xpm", &k, &k);
			else
				data.img = mlx_xpm_file_to_image(data.mlx, "./utils/empty_space_2.xpm", &k, &k);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx);
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
	int		i;

	lst = NULL;
	if (argc < 2)
		return (0);
	get_map(argv[1], &lst);
	tmp = lst;
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
	check_map(map, ft_lstsize(lst), (ft_lstlast(lst))->content);
	graphic(map, i, ft_strlen(map[0]));
	// system("leaks so_long");
}
