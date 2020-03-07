/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:00:50 by bbaudry           #+#    #+#             */
/*   Updated: 2020/03/02 16:11:31 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strdup(char *s1)
{
	int		len;
	char	*cpy;
	int		x;

	x = -1;
	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len])
	{
		len++;
	}
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	while (++x < len)
		cpy[x] = s1[x];
	cpy[x] = '\0';
	return (cpy);
}

static	int		ft_readdeux(int fd, char **toreturn, char ***saved)
{
	int		ret;
	char	courant[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	courant[BUFFER_SIZE] = '\0';
	while (1)
	{
		i = 0;
		if ((ret = read(fd, courant, BUFFER_SIZE)) <= 0)
			break ;
		if (!(*toreturn = ft_strjoin(*toreturn, courant, &i)))
			return (-1);
		if (courant[i] == '\n')
			break ;
	}
	if (ret < 0)
		return (-1);
	if (courant[i + 1] != '\0')
		if (!(**saved = ft_strdup(&courant[i + 1])))
			return (-1);
	if (ret == 0)
		return (0);
	return (1);
}

static	int		ft_read(int fd, char ***line, char **saved)
{
	char	*toreturn;
	int		ret;

	if (*saved)
	{
		if (!(toreturn = ft_strdup(*saved)))
			return (-1);
		free(*saved);
		*saved = NULL;
	}
	else
	{
 		if (!(toreturn = (char *)malloc(1)))
			return (-1);
		toreturn[0] = '\0';
	}
	if ((ret = ft_readdeux(fd, &toreturn, &saved)) <= 0)
	{
		free(toreturn);
		return (ret);
	}
	if (!(**line = ft_strdup(toreturn)))
		return (-1);
	free(toreturn);
	return (ret);
}

static	int		ft_noread(char **saved, char ***line)
{
	char	*toreturn;
	char	*tmp;
	int		len;
	int		x;

	len = 0;
	x = -1;
	if (!(tmp = ft_strdup(*saved)))
		return (-1);
	free(*saved);
	*saved = NULL;
	while (tmp[len] != '\0' && tmp[len] != '\n')
			len++;
	if (!(toreturn = (char *)malloc(len + 1)))
		return (-1);
	toreturn[len] = '\0';
	while (len - 1 > x++)
		toreturn[x] = tmp[x];
	if (!(**line = ft_strdup(toreturn)))
		return (-1);
	free(toreturn);
	if (!(*saved = ft_strdup(&tmp[len + 1])))
		return (-1);
	free(tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static	char	*saved[255];
	int				ret;
	int				ok;
	int				x;

	ok = 0;
	x = 0;
	if (fd >= 0)
	{
		if (saved[fd])
		{
			while (saved[fd][++x])
				if (saved[fd][x] == '\n')
					ok = 1;
		}
		if (ok == 1)
			ret = ft_noread(&saved[fd], &line);
		else
			ret = ft_read(fd, &line, &saved[fd]);
		printf("\nline saved : [%s]\n\n", saved[fd]);
		return (ret);
	}
	return (-1);
}
