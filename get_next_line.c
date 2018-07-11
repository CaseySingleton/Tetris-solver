/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 13:25:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/05 15:52:37 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int			fill_line(char **line, char *extra)
{
	size_t		i;

	i = 0;
	while (extra[i] != '\n' && extra[i] != '\0')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	*line = ft_strncpy(*line, extra, i);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*extra;
	int				i;

	i = 0;
	if ((!extra && !(extra = ft_strnew(BUFF_SIZE))) || fd < 0)
		return (-1);
	while ((i = read(fd, extra + ft_strlen(extra), BUFF_SIZE)) > 0)
		if (!(extra = ft_realloc(extra, ft_strlen(extra) + i)))
			return (-1);
	fill_line(line, extra);
	extra += ft_strlen(*line);
	if (*extra++ != '\0')
		if (*extra != '\0')
			return (1);
	return (0);
}
