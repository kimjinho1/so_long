/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:45 by jinhokim          #+#    #+#             */
/*   Updated: 2022/09/22 15:13:37 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_img(t_info *info)
{
	int	img_len;

	info->img_len = 64;
	info->die_img_w = info->img_len * info->w;
	info->die_img_h = info->img_len * info->h;
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
	info->exit_img = mlx_xpm_file_to_image(info->mlx,
			"images/exit.xpm", &img_len, &img_len);
	info->die_img = mlx_xpm_file_to_image(info->mlx,
			"images/you_die.xpm", &info->die_img_w, &info->die_img_h);
}

void	init_info(t_info *info, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		perror_exit("infile error");
	close(fd);
	info->map_path = map_path;
	info->move_cnt = 0;
	info->p_cnt = 0;
	info->c_cnt = 0;
	info->e_cnt = 0;
	info->die = 0;
	info->mlx = mlx_init();
	init_img(info);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->h)
		free(info->map[i]);
	free(info->map);
}
