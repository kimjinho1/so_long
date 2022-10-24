/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:08:44 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 08:51:20 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_move2(t_info *info, int dy, int dx, char e)
{
	int	y;
	int	x;

	if (dy == 1)
	{
		y = info->y / info->img_len + 1;
		x = info->x / info->img_len;
		if (info->map[y][x] == e)
			return (1);
		x = (info->x + 48) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
	}
	else if (dx == 1)
	{
		y = info->y / info->img_len;
		x = info->x / info->img_len + 1;
		if (info->map[y][x] == e)
			return (1);
		y = (info->y + 48) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
	}
	return (0);
}

static int	check_move(t_info *info, int dy, int dx, char e)
{
	int	y;
	int	x;

	if (dy == -1)
	{
		y = (info->y + 16 * dy) / info->img_len;
		x = (info->x) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
		x = (info->x + 48) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
	}
	else if (dx == -1)
	{
		y = (info->y) / info->img_len;
		x = (info->x + 16 * dx) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
		y = (info->y + 48) / info->img_len;
		if (info->map[y][x] == e)
			return (1);
	}
	return (check_move2(info, dy, dx, e));
}

static void	just_move(t_info *info, int dy, int dx)
{
	int	l;

	l = info->img_len;
	if (info->y / l != (info->y + 16 * dy) / l || \
			info->x / l != (info->x + 16 * dx) / l)
		info->map[info->y / l][info->x / l] = '0';
	info->y += 16 * dy;
	info->x += 16 * dx;
	info->map[info->y / l][info->x / l] = 'P';
	info->move_cnt++;
	if (info->move_cnt > 0 && info->move_cnt % 8 == 0)
		enemy_control(info);
}

static void	user_move(t_info *info, int dy, int dx)
{
	if (check_move(info, dy, dx, '1'))
		return ;
	else if (check_move(info, dy, dx, 'Q'))
	{
		info->die = 1;
		return ;
	}
	else if (check_move(info, dy, dx, 'E'))
	{
		if (info->c_cnt == 0)
			mlx_destroy_exit(info);
		else
			return ;
	}
	if (check_move(info, dy, dx, 'C'))
	{
		info->c_cnt--;
		info->map[info->y / info->img_len + dy][info->x / \
					info->img_len + dx] = '0';
	}
	just_move(info, dy, dx);
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
