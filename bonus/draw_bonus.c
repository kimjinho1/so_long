/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:06:53 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/24 23:56:44 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_img(t_info *info, char c, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g_img, x, y);
	if (c == '1')
		mlx_put_image_to_window(info->mlx, info->win, info->w_img, x, y);
	else if (c == 'P')
	{
		if (info->move_cnt % 2)
			mlx_put_image_to_window(info->mlx, info->win, info->p2_img, x, y);
		else
			mlx_put_image_to_window(info->mlx, info->win, info->p1_img, x, y);
	}
	else if (c == 'Q')
		mlx_put_image_to_window(info->mlx, info->win, info->enemy_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(info->mlx, info->win, info->c_img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(info->mlx, info->win, info->exit_img, x, y);
}

static void	draw_move_cnt(t_info *info)
{
	char	*cnt_str;
	char	*move_cnt_str;
	int		l;
	int		w;

	cnt_str = ft_itoa(info->move_cnt);
	move_cnt_str = strjoin("move cnt: ", cnt_str);
	l = ft_strlen(move_cnt_str);
	w = (info->w - 2) * info->img_len + 16 - 10 * (l - 11);
	mlx_string_put(info->mlx, info->win, w, 8, \
					0xdc1a3a, move_cnt_str);
	free(cnt_str);
	free(move_cnt_str);
}

static void	draw_you_die(t_info *info)
{
	int	w;
	int	h;
	int	i;
	int	j;

	w = info->w * info->img_len / 2 - info->die_img_w / 2;
	h = info->h * info->img_len / 2 - info->die_img_h / 2;
	i = -1;
	j = -1;
	mlx_clear_window(info->mlx, info->win);
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
			mlx_put_image_to_window(info->mlx, info->win, info->black_img, \
										j * info->img_len, i * info->img_len);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->die_img, w, h);
}

void	draw_map(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	if (info->die == 1)
	{
		draw_you_die(info);
		return ;
	}
	mlx_clear_window(info->mlx, info->win);
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
			draw_img(info, info->map[i][j], \
					j * info->img_len, i * info->img_len);
	}
	draw_move_cnt(info);
}
