/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:09:17 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 08:53:44 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		perror_exit("argument error");
	init_info(&info, av[1]);
	init_die_img(&info);
	parse_map(&info);
	init_enemy_idx(&info);
	info.win = mlx_new_window(info.mlx, info.img_len * info.w,
			info.img_len * info.h, "zelda so_long");
	draw_map(&info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &mlx_destroy_exit, &info);
	mlx_loop(info.mlx);
	return (0);
}
