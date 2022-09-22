/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:06:53 by jinhokim          #+#    #+#             */
/*   Updated: 2022/09/22 15:06:55 by jinhokim         ###   ########.fr       */
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

void	draw_map(t_info *info)
{
	int		i;
	int		j;
	char	*move_cnt_str;

	i = -1;
	if (info->die == 1)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->die_img, 0, 0);
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
	move_cnt_str = ft_itoa(info->move_cnt);
	mlx_string_put(info->mlx, info->win, (info->w - 1) * info->img_len, 0, \
					0xdc1a3a, move_cnt_str);
	free(move_cnt_str);
}
