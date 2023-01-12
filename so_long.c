/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/11 21:34:11 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_char(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '1' || ptr[i] == '0' || ptr[i] == '\n')
			i++;
		else if (ptr[i] == 'P' || ptr[i] == 'C' || ptr[i] == 'E')
			i++;
		else
		{
			printf("Use the valid characters (0, 1, P, C, E)");
			exit(0);
		}
	}
}

int	check_newline(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if ((ptr[i] == '\n' && ptr[i+1] == '\n') || ptr[0] == '\n')
		{
			printf("You have a duplicate newline");
			exit(0);	
		}
		i++;
	}
	return (1);
}

void	check_len(char *ptr)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	while (ptr[len] && ptr[len] != '\n')
		len++;
	while (ptr[i])
	{
		if (ptr[i] == '\n' && j == len)
		{
			j = 0;
			i++;
		}
		else if (ptr[i] == '\n' && (j < len || j > len))
		{
			printf("The length of the lines is different");
			exit(0);
		}			
		i++;
		j++;
	}
}

void	check_map(char *ptr)
{
	check_char(ptr);
	check_newline(ptr);
	check_len(ptr);
}

int	main(int argc, char **argv)
{
	char	*s;
	int		i = 0;
	char	*ptr;
	char	**map;
	int 	fd;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);

	ptr = get_next_line(fd);
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		ptr = ft_strjoin(ptr, s);
		free(s);
		i++;
	}
	map = ft_split();
	printf("%s", ptr);
	// check_map(ptr);
    // printf("%s",ptr);
}
// int	main(int argc, char **argv)
// {
// 	// char	*s;
// 	char	**ptr;
// 	int 	fd;
// 	int i;

// 	i = 0;
// 	if (argc < 2)
// 		return (0);
// 	ptr = NULL;
// 	// ptr = ft_calloc((ft_strlen()+ 1), sizeof(char *));
// 	// if (!ptr)
// 	// 	return (NULL);
// 	fd = open(argv[1], O_RDONLY);
// 	ptr[0] = get_next_line(fd);
// 	// while (ptr[i])
// 	// {
// 	// 	ptr[i] = get_next_line(fd);
// 	// 	i++;
// 	// }
// 	// printf("%s", ptr[1]);
// 	// check_map(ptr);
//     // printf("%s",ptr);
// }
