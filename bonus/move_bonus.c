/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:08:44 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 02:58:58 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	user_move(t_info *info, int dy, int dx)
{
	if (info->map[info->y + dy][info->x + dx] == '1')
		return ;
	else if (info->map[info->y + dy][info->x + dx] == 'Q')
	{
		info->die = 1;
		return ;
	}
	else if (info->map[info->y + dy][info->x + dx] == 'E')
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	if (info->map[info->y + dy][info->x + dx] == 'C')
		info->c_cnt--;
	info->map[info->y][info->x] = '0';
	info->map[info->y + dy][info->x + dx] = 'P';
	info->move_cnt++;
	info->y += dy;
	info->x += dx;
	if (info->move_cnt > 0 && info->move_cnt % 8 == 0)
		enemy_control(info);
}

int	key_press(int key, t_info *info)
{
	if (info->die == 1)
		mlx_destroy_exit(info);
	if (key == KEY_W)
		user_move(info, -1, 0);
	else if (key == KEY_A)
		user_move(info, 0, -1);
	else if (key == KEY_S)
		user_move(info, 1, 0);
	else if (key == KEY_D)
		user_move(info, 0, 1);
	else if (key == KEY_ESC)
		mlx_destroy_exit(info);
	else
		return (0);
	draw_map(info);
	return (1);
}
