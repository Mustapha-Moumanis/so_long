/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:42:10 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/17 01:24:04 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// struct help

// typedef struct s_map
// {
// 	int	player;
// 	int	collectible;
// 	int	exit;
// }	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	int		player;
	int		collectible;
	int		exit;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
}	t_data;

// linked list :

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// libft function
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned	int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);

// checker function
void	ft_error(char *error_msg);
void	check_map(char **map, int len, char *last_line, t_data *data);
void	check_char(char **map, int len, t_data *data);
void	check_file_format(char *file_name);
void	check_len(char **ptr);
void	check_newline(char **ptr, char *last_line);
int		is_valid_ext(char *file_name, char *ext);

#endif