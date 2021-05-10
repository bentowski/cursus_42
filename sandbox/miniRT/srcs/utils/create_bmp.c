/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:21 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 00:35:21 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	create_bmpfileheader(t_bmp_h *header, int size)
{
	ft_bzero(header, sizeof(t_bmp_h));
	header->bmp_type[0] = 'B';
	header->bmp_type[1] = 'M';
	header->file_size = HEADER_BYTES + size;
	header->reserved1 = 0;
	header->reserved2 = 9;
	header->offset = HEADER_BYTES;
}

static void	create_bmpdibheader(t_res *res, t_dib_h *header, int size)
{
	int	ppm;

	ppm = DEFAULT_DPI * PPM_CONV_FACTOR;
	ft_bzero(header, sizeof(t_dib_h));
	header->size_header = sizeof(t_dib_h);
	header->width = res->width;
	header->height = res->height;
	header->planes = DEFAULT_BIPLANES;
	header->bit_count = TRUE_COLOR;
	header->compr = 0;
	header->img_size = HEADER_BYTES + size;
	header->ppm_x = ppm;
	header->ppm_y = ppm;
	header->clr_used = 0;
	header->clr_important = 0;
}

static void	edit_bmp(t_env *env, int fd)
{
	t_bmp_h	file_header;
	t_dib_h	dib_header;
	int		size;

	size = env->map->res->width * env->map->res->height * 3;
	create_bmpfileheader(&file_header, size);
	create_bmpdibheader(env->map->res, &dib_header, size);
	write(fd, &(file_header.bmp_type), 2);
	write(fd, &(file_header.file_size), 4);
	write(fd, &(file_header.reserved1), 2);
	write(fd, &(file_header.reserved2), 2);
	write(fd, &(file_header.offset), 4);
	write(fd, &(dib_header.size_header), 4);
	write(fd, &(dib_header.width), 4);
	write(fd, &(dib_header.height), 4);
	write(fd, &(dib_header.planes), 2);
	write(fd, &(dib_header.bit_count), 2);
	write(fd, &(dib_header.compr), 4);
	write(fd, &(dib_header.img_size), 4);
	write(fd, &(dib_header.ppm_x), 4);
	write(fd, &(dib_header.ppm_y), 4);
	write(fd, &(dib_header.clr_used), 4);
	write(fd, &(dib_header.clr_important), 4);
}

void		write_bmpdata(t_env *env, int fd)
{
	int					x;
	int					y;
	unsigned long int	*p;

	y = env->map->res->height - 1;
	while (y > -1)
	{
		x = 0;
		while (x < env->map->res->width)
		{
			p = (unsigned long int *)(env->img.addr +
					(x + env->map->res->width * y) * 4);
			if (write(fd, p, 3) < 0)
				return ;
			x++;
		}
		y--;
	}
}

void		create_bmp(t_env *env)
{
	int		fd;
	char	*filename;

	filename = "miniRT.bmp";
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (fd < 0)
		printf("%s\n%s", "Error", "bmp file corrupted");
	else
	{
		edit_bmp(env, fd);
		write_bmpdata(env, fd);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
