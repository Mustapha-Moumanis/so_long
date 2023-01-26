/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:42:10 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/26 02:14:32 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "../src/get_next_line.h"

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

// struct help :

typedef struct s_data
{
	char	**map;
	t_list	*tmp;
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
	int		n_m;
	int		x;
	int		y;
	int		col_len;
	int		row_len;
	int		c_animation;
}	t_data;

// libft function
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned	int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);

// checker function
void	ft_error(char *error_msg);
int		ft_close(void);
int		ft_winner(void);
void	check_map(int row_len, char *last_line, t_data *data);
void	check_char(int len, t_data *data);
void	check_file_format(char *file_name);
void	check_len(char **ptr);
void	check_newline(char **ptr, char *last_line);
int		is_valid_ext(char *file_name, char *ext);
void	check_collectible(char **copy_map, int i, int j);
void	flood_fill(char **copy_map, int i, int j, int r);
int		check_path(t_data *data, int r);

// move function
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	get_img(t_data *data, int i, int j);
void	player_img(t_data *data, int d);
void	get_map(char *file_name, t_list **lst);
void	images(t_data *data);
void	c_animation(t_data *data, int i, int j);

#endif