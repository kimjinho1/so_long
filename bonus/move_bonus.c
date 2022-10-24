/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:08:44 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 02:43:36 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	*get_direction_enemy_can_move(t_info *info, int id)
{
	int	y;
	int	x;
	int	*d;
	int	i;

	y = info->enemy_idx[id][0];
	x = info->enemy_idx[id][1];
	d = (int *)malloc(sizeof(int) * 4);
	i = -1;
	if (info->map[y - 1][x] == 'P' || info->map[y - 1][x] == '0')
		d[++i] = 0;
	if (info->map[y][x - 1] == 'P' || info->map[y][x - 1] == '0')
		d[++i] = 1;
	if (info->map[y + 1][x] == 'P' || info->map[y + 1][x] == '0')
		d[++i] = 2;
	if (info->map[y][x + 1] == 'P' || info->map[y][x + 1] == '0')
		d[++i] = 3;
	while (++i < 4)
		d[i] = -1;
	return (d);
}

static void	enemy_move(t_info *info, int id, int dy, int dx)
{
	int	y;
	int	x;

	y = info->enemy_idx[id][0];
	x = info->enemy_idx[id][1];
	info->map[y][x] = '0';
	info->map[y + dy][x + dx] = 'Q';
	info->enemy_idx[id][0] += dy;
	info->enemy_idx[id][1] += dx;
}

static void	enemy_control(t_info *info)
{
	int	i;
	int	*d;
	int	cnt;
	int	n;

	i = -1;
	while (++i < info->enemy_cnt)
	{
		d = get_direction_enemy_can_move(info, i);
		cnt = -1;
		while (++cnt < 4 && d[cnt] != -1)
			;
		n = -1;
		if (d[0] != -1)
			n = rand() % cnt;
		if (n != -1 && d[n] == 0)
			enemy_move(info, i, -1, 0);
		else if (n != -1 && d[n] == 1)
			enemy_move(info, i, 0, -1);
		else if (n != -1 && d[n] == 2)
			enemy_move(info, i, 1, 0);
		else if (n != -1 && d[n] == 3)
			enemy_move(info, i, 0, 1);
		free(d);
	}
}

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
