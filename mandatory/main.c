/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:54:46 by jinhokim          #+#    #+#             */
/*   Updated: 2022/10/25 08:46:45 by jinhokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 5)
		return (0);
	if (path[i - 4] != '.' || path[i - 3] != 'b' || path[i - 2] != 'e' || \
			path[i - 1] != 'r')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		perror_exit("argument error");
	if (!check_ber(av[1]))
		perror_exit("infile error");
	init_info(&info, av[1]);
	parse_map(&info);
	info.win = mlx_new_window(info.mlx, info.img_len * info.w,
			info.img_len * info.h, "zelda so_long");
	draw_map(&info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &mlx_destroy_exit, &info);
	mlx_loop(info.mlx);
	return (0);
}
