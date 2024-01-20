/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:35:35 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/11 00:29:59 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char *line, char *buff, int check)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!line || !buff)
		return (ft_free(NULL, NULL, &buff, 2));
	t = ft_strlen(line) + ft_strlen(buff);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (NULL);
	while (line[j])
		new[i++] = line[j++];
	j = 0;
	while (buff[j])
		new[i++] = buff[j++];
	new[i] = '\0';
	if (check == 0)
		get_rmn(buff, buff, 0);
	if (check == 1)
		ft_free(&line, NULL, &buff, 4);
	return (new);
}

char	*get_the_line(int fd, char *next, char *line)
{
	ssize_t	get_rd;
	char	*buff;

	while (1)
	{
		buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!buff)
			return (ft_free(&line, NULL, NULL, 0));
		get_rd = read(fd, buff, BUFFER_SIZE);
		if (get_rd == -1)
			return (ft_free(&line, NULL, &buff, 4));
		if (get_rd == 0 && !ft_free(NULL, NULL, &buff, 2))
			break ;
		buff[get_rd] = '\0';
		line = ft_strjoin(line, fill(buff), 1);
		if (line && check_nl(buff))
		{
			get_rmn(next, buff, 1);
			break ;
		}
		ft_free(NULL, NULL, &buff, 2);
	}
	if (line && line[0])
		return (line);
	return (ft_free(&line, NULL, NULL, 0));
}

char	*ft_last(int fd, char *next, char *line)
{
	line = ft_strjoin(line, next, 0);
	if (!line)
		return (NULL);
	line = get_the_line(fd, next, line);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	line = "";
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (ft_free(NULL, &next_line, NULL, 1));
	if (!next_line)
	{
		next_line = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!next_line)
			return (NULL);
		next_line[0] = '\0';
	}
	if (check_nl(next_line))
	{
		line = fill(next_line);
		if (!line)
			return (NULL);
		get_rmn(next_line, next_line, 0);
	}
	else if (check_nl(next_line) == 0)
		line = ft_last(fd, next_line, line);
	if (line && line[0])
		return (line);
	return (ft_free(&line, &next_line, NULL, 3));
}
