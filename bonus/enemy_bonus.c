/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:56:16 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 03:02:47 by jinhokim         ###   ########.fr       */
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
	if (info->map[y + dy][x + dx] == 'P')
	{
		info->die = 1;
		return ;
	}
	info->map[y + dy][x + dx] = 'Q';
	info->enemy_idx[id][0] += dy;
	info->enemy_idx[id][1] += dx;
}

void	enemy_control(t_info *info)
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
