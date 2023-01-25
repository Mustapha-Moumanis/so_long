/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:23:00 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/25 05:13:30 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *error_msg)
{
	write(2, "\033[0;31mError\n", 15);
	write(1, error_msg, ft_strlen(error_msg));
	exit (0);
}

int	ft_close(void)
{
	write(1, "\033[0;33mThe game is closed\n", 27);
	exit (0);
}

int	ft_winner(void)
{
	write(1, "\033[0;32mGood job. you win\n", 26);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_valid_ext(char *file_name, char *ext)
{
	char	*last_accur;

	last_accur = ft_strrchr(file_name, '.');
	if (!last_accur || ft_strlen(last_accur) < ft_strlen(ext))
		return (0);
	return (ft_strcmp(last_accur, ext) == 0);
}
