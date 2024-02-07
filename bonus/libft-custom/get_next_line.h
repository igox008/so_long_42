/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:35:02 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/11 00:30:37 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*fill(char *buff);
void	get_rmn(char *dst, char *src, int check);
char	*ft_free(char **line, char **next, char **buff, int check);
char	*ft_last(int fd, char *next, char *line);
char	*get_the_line(int fd, char *next, char *line);
size_t	ft_strlen(const char *str);

#endif