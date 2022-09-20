/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:12:56 by jinhokim          #+#    #+#             */
/*   Updated: 2022/09/20 05:07:34 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define BUFFER_SIZE 	42
# define OPEN_MAX 		10240

typedef struct s_info
{
	char	*map_path;
	int		fd;
	char	**map;
	int		h;
	int		w;
	int		y;
	int		x;
	int		move_cnt;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		die;
	int		img_len;
	int		die_img_w;
	int		die_img_h;
	void	*mlx;
	void	*win;
	void	*g_img;
	void	*w_img;
	void	*p1_img;
	void	*p2_img;
	void	*enemy_img;
	void	*c_img;
	void	*exit_img;
	void	*die_img;
}				t_info;

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);

int				get_next_line(int fd, char **line);

void			init_img(t_info *info);
void			init_info(t_info *info, char *map_path);
void			free_info(t_info *info);

void			perror_exit(char *opt);
void			perror_free_exit(char *opt, t_info *info);
int				mlx_destroy_exit(t_info *info);
char			*ft_itoa(int nb);

int				check_map_width_height(t_info *info);
void			check_wall(t_info *info);
void			check_element(t_info *info, int i, int j);
void			check_map_element(t_info *info);
void			parse_map(t_info *info);

void			draw_img(t_info *info, char c, int x, int y);
void			draw_map(t_info *info);

void			move_up(t_info *info);
void			move_left(t_info *info);
void			move_down(t_info *info);
void			move_right(t_info *info);
int				key_press(int key, t_info *info);

#endif
