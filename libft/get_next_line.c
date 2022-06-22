/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:36:16 by molesen           #+#    #+#             */
/*   Updated: 2021/12/16 15:45:50 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_not_end_of_str(char **str, char **line, int len)
{
	char	*temp;

	*line = ft_strsub(str[0], 0, len);
	if (!(*line))
	{
		str = ft_free2d(str);
		return (ERROR);
	}
	temp = str[0];
	str[0] = ft_strdup(&temp[len + 1]);
	if (!str[0])
		return (ERROR);
	ft_strdel(&temp);
	if (str[0][0] == '\0')
		ft_strdel(&str[0]);
	return (0);
}

static int	ft_str_to_line(char **str, char **line)
{
	int	len;

	len = ft_strlen_stop(str[0], '\n');
	if (str[0][len] == '\0')
	{
		*line = ft_strdup(str[0]);
		if (!(*line))
		{
			str = ft_free2d(str);
			return (ERROR);
		}
		ft_strdel(&str[0]);
	}
	else
		if (ft_not_end_of_str(str, line, len) == ERROR)
			return (ERROR);
	return (0);
}

static int	ft_buf_to_str( char **str, char *buf, char **line)
{
	char	*temp;

	if (str[0])
	{
		temp = str[0];
		str[0] = ft_strjoin(temp, buf);
		ft_strdel(&temp);
		if (!str[0])
		{
			ft_strdel(&str[0]);
			return (ERROR);
		}
	}
	else
	{
		str[0] = ft_strdup(buf);
		if (!str[0])
			return (ERROR);
	}
	if (ft_strchr(str[0], '\n') != NULL)
		if (ft_str_to_line(str, line) == ERROR)
			return (ERROR);
	return (0);
}

int	get_next_line(FILE *fd, char **line)
{	
	static char	*str[1];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!line || BUFF_SIZE < 1)
		return (ERROR);
	*line = NULL;
	while ((!str[0] || ft_strchr(str[0], '\n') == NULL) && !(*line))
	{
		ret = fread(buf, sizeof(char), BUFF_SIZE, fd);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (ft_buf_to_str(str, buf, line) == ERROR)
			return (ERROR);
	}
	if ((ret == 0 && !str[0]) && !(*line))
		return (0);
	if (!(*line))
		if (ret == -1 || ft_str_to_line(str, line) == ERROR)
			return (ERROR);
	return (1);
}
