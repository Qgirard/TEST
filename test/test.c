/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:42:56 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/22 17:37:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

int		main(void)
{
	void	*img_ptr;
	char	*str;
	int		bpp;
	int		size_line;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	img_ptr = NULL;
	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	img_ptr = mlx_new_image(mlx_ptr, 167, 500);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (i <= 83500)
	{
		((unsigned int *)str)[i] = 255;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	i = 0;
	img_ptr = mlx_new_image(mlx_ptr, 167, 500);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (i <= 83500)
	{
		((unsigned int *)str)[i] = 16777215;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 167, 0);
	i = 0;
	img_ptr = mlx_new_image(mlx_ptr, 167, 500);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (i <= 83500)
	{
		((unsigned int *)str)[i] = 16711680;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 334, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
