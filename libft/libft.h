/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:16:34 by molesen           #+#    #+#             */
/*   Updated: 2021/12/17 11:31:43 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define BUFF_SIZE	32
# define ERROR	-1
# define TRUE	1
# define FALSE	0

int		get_next_line(FILE *fd, char **line);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen_stop(char *str, char c);
size_t	ft_strlen(const char *str);
char	**ft_free2d(char **dest);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
