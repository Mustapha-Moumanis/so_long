/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:20:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/16 22:05:12 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_file_format(char *file_name)
{
	if (!is_valid_ext(file_name, ".ber"))
		ft_error("please check file format \".ber\"\n");
}

void	check_newline(char **ptr, char *last_line)
{
	int	i;

	i = 0;
	if (last_line[ft_strlen(last_line) - 1] == '\n')
		ft_error("You have a newline in the last line");
	while (ptr[i])
	{
		if (!ptr[i][0])
			ft_error("You have a duplicate newline");
		i++;
	}
}

void	check_len(char **ptr)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[i])
	{
		j = ft_strlen(ptr[i]);
		if (j < len || j > len)
			ft_error("The length of the lines is different");
		i++;
	}
	if (j < 3)
		ft_error("At least three characters");
	if (i < 3)
		ft_error("At least three lines");
}
