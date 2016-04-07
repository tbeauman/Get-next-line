/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:21:45 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/27 13:32:44 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		remplis_line(char **line, char *lignes)
{
	char	*str;

	str = ft_strchr(lignes, '\n');
	if (str)
	{
		str[0] = 0;
		*line = ft_strdup(lignes);
		ft_memmove(lignes, &str[1], ft_strlen(&str[1]) + 1);
		return (1);
	}
	if (ft_strlen(lignes) > 0)
	{
		*line = ft_strdup(lignes);
		*lignes = 0;
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*lignes[256];
	char		*temp;
	int			rr;

	if (fd < 0 || fd > 255 || !line)
		return (-1);
	if (!lignes[fd] && !(lignes[fd] = ft_strnew(1)))
		return (-1);
	while (!ft_strchr(lignes[fd], '\n'))
	{
		if ((rr = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		if (rr == 0)
			break ;
		buf[rr] = 0;
		temp = ft_strjoin(lignes[fd], buf);
		free(lignes[fd]);
		lignes[fd] = temp;
	}
	return (remplis_line(line, lignes[fd]));
}
