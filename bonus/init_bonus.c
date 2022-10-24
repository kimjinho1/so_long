/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:45 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 02:08:11 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->h)
		free(info->map[i]);
	free(info->map);
	if (info->enemy_cnt > 0)
	{
		while (info->enemy_cnt > 0)
			free(info->enemy_idx[--info->enemy_cnt]);
		free(info->enemy_idx);
	}
}

static void	init_img(t_info *info)
{
	int	img_len;

	info->img_len = 64;
	info->g_img = mlx_xpm_file_to_image(info->mlx,
			"images/g.xpm", &img_len, &img_len);
	info->w_img = mlx_xpm_file_to_image(info->mlx,
			"images/w.xpm", &img_len, &img_len);
	info->p1_img = mlx_xpm_file_to_image(info->mlx,
			"images/p1.xpm", &img_len, &img_len);
	info->p2_img = mlx_xpm_file_to_image(info->mlx,
			"images/p2.xpm", &img_len, &img_len);
	info->enemy_img = mlx_xpm_file_to_image(info->mlx,
			"images/enemy.xpm", &img_len, &img_len);
	info->c_img = mlx_xpm_file_to_image(info->mlx,
			"images/c.xpm", &img_len, &img_len);
	info->black_img = mlx_xpm_file_to_image(info->mlx,
			"images/black.xpm", &img_len, &img_len);
	info->exit_img = mlx_xpm_file_to_image(info->mlx,
			"images/exit.xpm", &img_len, &img_len);
}

void	init_info(t_info *info, char *map_path)
{
	int	fd;

	if (!check_ber(map_path))
		perror_exit("infile error");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		perror_exit("infile error");
	close(fd);
	info->map_path = map_path;
	info->move_cnt = 0;
	info->p_cnt = 0;
	info->c_cnt = 0;
	info->e_cnt = 0;
	info->enemy_cnt = 0;
	info->die = 0;
	info->mlx = mlx_init();
	init_img(info);
}

void	init_die_img(t_info *info)
{
	if (info->w < 15 || info->h < 8)
	{
		info->die_img = mlx_xpm_file_to_image(info->mlx, \
			"images/you_die_small.xpm", &info->die_img_w, &info->die_img_h);
	}
	else
	{
		info->die_img = mlx_xpm_file_to_image(info->mlx, \
			"images/you_die.xpm", &info->die_img_w, &info->die_img_h);
	}
}

void	init_enemy_idx(t_info *info)
{
	int	i;
	int	j;
	int	enemy_i;

	if (info->enemy_cnt < 1)
		return ;
	info->enemy_idx = (int **)malloc(sizeof(int *) * info->enemy_cnt);
	i = -1;
	enemy_i = 0;
	while (++i < info->h)
	{
		j = -1;
		while (++j < info->w)
		{
			if (info->map[i][j] == 'Q')
			{
				info->enemy_idx[enemy_i] = (int *)malloc(sizeof(int) * 2);
				info->enemy_idx[enemy_i][0] = i;
				info->enemy_idx[enemy_i][1] = j;
				enemy_i++;
			}
		}
	}
	srand(time(NULL));
}
